//
// Created by neta on 1/8/19.
//

#ifndef MILESTONE3_BESTFIRSTSEARCH_H
#define MILESTONE3_BESTFIRSTSEARCH_H
#include <algorithm>
#include "Searcher.h"
#include <queue>
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
    // אולי להפוך שיקבל state t
    bool isExist( priority_queue<State<T> *, vector<State<T> *>, Comp> open, State<T> *state) {
        while(!open.empty()) {
            State<T> *temp = open.top;
            if (temp->Equal(state)) {
                return true;
            }
            open.pop();
        }
        return false;
    }
    priority_queue<State<T>> updateQueueOpen(priority_queue<State<T> *, vector<State<T> *>, Comp> open) {
        priority_queue<State<T>*> temp;
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
        string path="";
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
                    if (!isExist(open, neighbor) && InClosed(neighbor, closed)) {
                        //maybe &
                        neighbor->setCameFrom(n);
                        open.push(neighbor);
                    }
                    else if (neighbor->getCost() > neighbor->getCost() - neighbor->getDad()->getCost() + n->getCost()) {
                        if (!isExist(open,neighbor)) {
                            open.push(neighbor);
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
//                while (!n->Equal(searchable->getInitialNode())) {
//                    //path+=n->getDad()->getState();
//                    //n = n->getDad();
//                }
                // std::reverse(path.begin(),path.end());
                return path;
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