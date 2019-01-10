//
// Created by neta on 1/8/19.
//

#ifndef MILESTONE3_BESTFIRSTSEARCH_H
#define MILESTONE3_BESTFIRSTSEARCH_H
#include <algorithm>
#include "Searcher.h"
#include <queue>
#include "iostream"
#include <unordered_set>
template <class T>
class BestFirstSearch: public Searcher<T> {
    class Comp {
    public:
        bool operator()(State<T>* left, State<T>* right) {
            return (left->getCost()) > (right->getCost());
        }
    };
public:
    bool isExist( priority_queue<State<T> *, vector<State<T> *>, Comp> open, State<T> *state) {
        while (!open.empty()) {
            if (state->Equal(open.top())) {
                return true;
            }
            open.pop();
        }
        return false;
    }
    priority_queue<State<T> *, vector<State<T> *>, Comp> updateQueueOpen(priority_queue<State<T> *, vector<State<T> *>, Comp> open) {
        priority_queue<State<T> *, vector<State<T> *>, Comp> temp;
        while (!open.empty()) {
            State<T>* node = open.top();
            temp.push(node);
            open.pop();
        }
        return temp;
    }

    string search(Searchable<T> *searchable) override {
        priority_queue<State<T> *, vector<State<T> *>, Comp> open;
        vector<State<T>*> closed;
        vector<State<T>*> totalPoints;
        string path="";
        string finalPath="";
        double tempCost=0;
        double value;
        open.push(searchable->getInitialState());
        while (!open.empty()) {
            State<T> *n = open.top();
            closed.push_back(n);
            if ((n->Equal(searchable->getInitialState())) && n->getCost() == -1) {
                path = "-1";
                return path;
            }
            open.pop();
            if (!n->Equal(searchable->getGoalState())) {
                vector<State<T> *> neighbors = searchable->getAllPossibleStates(n);
                for (State<T> *neighbor : neighbors) {
                    if (!isExist(open, neighbor) && !InClosed(neighbor, closed)) {
                        neighbor->setCameFrom(n);
                        tempCost=neighbor->getCost();
                        neighbor->setCost(neighbor->getCost()+neighbor->getDad()->getCost());
                        open.push(neighbor);
                    }
                    else if (neighbor->getDad()==NULL) {
                        continue;
                    }
                    else if (neighbor->getCost() > tempCost + neighbor->getDad()->getCost() ) {
                        if (!isExist(open,neighbor)) {
                            open.push(neighbor);
                            closed.erase(std::remove(closed.begin(), closed.end(), neighbor), closed.end());
                        }
                        else {
                            neighbor->setCameFrom(n);
                            neighbor->setCost(neighbor->getCost() - neighbor->getDad()->getCost() + n->getCost());
                            open = updateQueueOpen(open);
                        }
                    }
                }
            }
            //n is the goal state
            else {
                bool first = true;
                while (n != NULL) {
                    if (first){
                        n->totalCost= n->getCost();
                        std::cout<< n->totalCost<<endl;
                        first=false;
                    }
                    path+=to_string((int) n->getCost())+" ";
                    totalPoints.push_back(n);
                    n = n->getDad();
                }
                std::reverse(totalPoints.begin(),totalPoints.end());
                finalPath= searchable->getPathSolution(totalPoints);
                return finalPath;
            }
        }
        return path;
    }

    bool InClosed(State<T> *state, vector<State<T> *> statesClosed) {
        for (State<T> *s : statesClosed) {
            if (state->Equal(s)) {
                return true;
            }
        }
        return false;
    }

    int getNumberOfNodesEvaluated() {
        return 5;
    }
};

#endif //MILESTONE3_BESTFIRSTSEARCH_H