//
// Created by efrat on 06/01/19.
//

#ifndef MILESTONE2_BFS_H
#define MILESTONE2_BFS_H
// Program to print BFS traversal from a given
// source vertex. BFS(int s) traverses vertices
// reachable from s.
#include<iostream>
#include <list>
#include "vector"
using namespace std;

#include "Searchable.h"
#include "Searcher.h"
#include "State.h"
// This class represents a directed graph using
// adjacency list representation
template <class T>
class BFS: public Searcher<T> {
    vector<State<T>> search(Searchable<T> searchable) override {
        list<State<T>> openList = searchable.getInitialState();
        searchable.setCurrVisited();
        vector<State<T>> trace;
        while (openList.size() > 0) {
            State<T> n = openList.front();
            trace.push_back(n);
            openList.pop_front();
            if (n.equals(searchable.getGoalState())) {
                return trace();
            }
            list<State<T>> succerssors = searchable.getAllPossibleStates(n);
            for (State<T> state : succerssors) {
                bool visited = state.getVisited();
                if (!visited) {
                    state.setVisited();
                    openList.push_back(state);
                }
            }
        }
        return nullptr;
    }
};


#endif //MILESTONE2_BFS_H
