//
// Created by efrat on 06/01/19.
//

#ifndef MILESTONE2_DFS_H
#define MILESTONE2_DFS_H
#include "Searcher.h"
#include <stack>
#include "string"
#define NO_PATH "-1";
using namespace std;

template <class T>
class DFS : Searcher<T> {
    int cost = 0;
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
        while (!qu.empty()) {
            current = qu.top();
            qu.pop();
            counter++;
            if (!wasVisited(visited, current)) {
                visited.push_back(current);
            }

            if(current->Equal(searchable->getGoalState())){

                while (current != NULL) {
                    cost+=current->getCost();
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
                }
            }
        }
        return NO_PATH;
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

    virtual double getPathCost() {
        return cost;
    }
};

#endif //MILESTONE2_DFS_H
