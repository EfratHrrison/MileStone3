#include "Searcher.h"
#include <algorithm>
#include <list>
#include <queue>
#define NO_PATH "-1";
template<class T>
class BFS : public Searcher<T> {
    int counter=0;
public:
    string search(Searchable<T> *searchable) {
        vector<State<T> *> visit;
        string finalPath="";
        queue<State<T>*> qu;
        vector<State<T> *> neighbors;
        State<T> *current;
        vector<State<T>*> totalPoints;
        qu.push(searchable->getInitialState());
        visit.push_back(searchable->getInitialState());
        counter++;
        while (!qu.empty()) {
            current = qu.front();
            if(current->Equal(searchable->getGoalState())){
                while (current != NULL) {
                    //counter++;
                    totalPoints.push_back(current);
                    current = current->getDad();
                }
                std::reverse(totalPoints.begin(),totalPoints.end());
                finalPath= searchable->getPathSolution(totalPoints);
                return finalPath;
            }
            neighbors = searchable->getAllPossibleStates(current);
            qu.pop();
            for (State<T> *neighbor : neighbors) {
                if (!wasVisited(visit,neighbor)) {
                    neighbor->setCameFrom(current);
                    visit.push_back(neighbor);
                    counter++;
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
};