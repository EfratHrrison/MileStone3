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

public:
    // אולי להפוך שיקבל state t
    // לוודא שזה לא דורס את התור
    bool isExist(priority_queue <State<T>> open, T node) {
       while(!open.empty()) {
           State<T> temp = open.top;
           if (temp.Equal(node)) {
               return true;
           }
           open.pop();
       }
       return false;
    }
    // לטפל בCOST !!!!!
    vector<T> search(Searchable<T> *searchable) override {
        priority_queue<State<T>> open;
        unordered_set<State<T>> closed;
        vector<T> path;
        double value;
        open.push(searchable->getInitialState());
        while (!open.empty()) {
            State<T> n = open.top();
            closed.insert(n);
            open.pop();
            if (!n.Equal(searchable->getGoalNode())) {
                for (State<T> s:searchable->getAllPossibleStates(n)) {
                    if (!isExist(open, s.getState()) && closed.count(s) != 0) {
                        s.setCameFrom(&n);
                        open.push(s);
                    }
                }
            }
            //n is the goal state  hgf
            else {
                while (!n.Equal(searchable->getInitialNode())) {
                    path.push_back(n.getDad().getState());
                    n = n.getCameFrom();
                }
                std::reverse(path.begin(),path.end());
                return path;
            }
        }
    }
};

#endif //MILESTONE3_BESTFIRSTSEARCH_H
