//
// Created by efrat on 06/01/19.
//

#ifndef MILESTONE2_DFS_H
#define MILESTONE2_DFS_H
#include "Searcher.h"
#include <stack>
#include "string"
using namespace std;

template <class T>
class DFS : Searcher<T> {
    int counter=0;
public:
    string search(Searchable<T> *searchable) {
        stack<State<T> *> qu;
        vector<State<T> *> neighbors;
        vector<State<T>*> totalPoints;
        vector<State<T> *> visited;
        State<T> *current;
        string finalPath="";

        qu.push(searchable->getInitialState());
        counter++;

        while (!qu.empty()) {
            current = qu.top();
            qu.pop();

            if (!wasVisited(visited, current)) {
                visited.push_back(current);
            }

            if(current->Equal(searchable->getGoalState())){

                while (current != NULL) {

                    totalPoints.push_back(current);
                    current = current->getDad();
                }
                reverse(totalPoints.begin(),totalPoints.end());
                finalPath= searchable->getPathSolution(totalPoints);
                return finalPath;
            }
            neighbors = searchable->getAllPossibleStates(current);
            for (State<T> *neighbor : neighbors) {
                if (!wasVisited(visited,neighbor)) {
                    neighbor->setCameFrom(current);
                    qu.push(neighbor);
                    counter++;
                }
            }
        }
        return "-1";
    }




    bool wasVisited(vector<State<T> *> visited,State<T> *current ){
        for (auto state:visited) {
            if (current->Equal(state)) {
                return true;
            }
        }
        return false;
    }

    int getNumberOfNodesEvaluated() {
        return counter;
    }
};

#endif //MILESTONE2_DFS_H
