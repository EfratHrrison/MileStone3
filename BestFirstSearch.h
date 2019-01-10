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
    bool isExist(priority_queue <State<T>> open, T node) {
       while(!open.empty()) {
           State<T> *temp = open.top;
           if (temp->Equal(node)) {
               return true;
           }
           open.pop();
       }
       return false;
    }
    priority_queue<State<T>*> updateQueueOpen(priority_queue<State<T>*> &queueOpen) {
        priority_queue<State<T>*> temp;
        while (!queueOpen.empty()) {
            State<T>* node = queueOpen.top();
            temp.push(node);
            queueOpen.pop();
        }
        return temp;
    }

    string search(Searchable<T> *searchable) override {
        priority_queue<State<T>*, vector<State<T>*>, Comp> open;
        unordered_set<State<T>> closed;
        string path="";
        double value;
        open.push(searchable->getInitialState());
        while (!open.empty()) {
            State<T> *n = open.top();
            closed.insert(n);
            if ((n->Equal(searchable->getInitialState())) && n->getCost() == -1) {
                path = "-1";
                return path;
            }
            open.pop();
            if (!n.Equal(searchable->getGoalNode())) {
                for (State<T> *s:searchable->getAllPossibleStates(n)) {
                    if (!isExist(open, s->getState()) && closed.find(s) != searchable->getAllPossibleStates(n).end()) {
                        //maybe &
                        s->setCameFrom(n);
                        open.push(s);
                    }
                    else if (s->getCost() > s->getCost() - s->getDad().getCost() + n->getCost()) {
                        if (!isExist(s)) {
                            open.push(s);
                        }
                        else {
                            s->setCameFrom(n);
                            s->setCost(s->getCost() - s->getDad().getCost() + n->getCost());
                            open = updateQueueOpen(open);
                        }
                    }
                }

            }
            //n is the goal state
            else {
                while (!n.Equal(searchable->getInitialNode())) {
                    path+=n.getDad()->getState();
                    n = n.getDad();
                }
               // std::reverse(path.begin(),path.end());
                return path;
            }
        }
        return path;
    }

    bool InClosed(State<T> *state, vector<State<T> *> statesClosed) {
        for (State<T> *s : statesClosed) {
            if (state->equals(s)) {
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
