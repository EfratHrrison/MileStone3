//
// Created by neta on 1/8/19.
//

#ifndef MILESTONE3_SEARCHER_H
#define MILESTONE3_SEARCHER_H
#include <string>
#include "Searchable.h"

using namespace std;

template <class T>

class Searcher {
public:
    virtual vector<State<T>> search (Searchable<T> searchable) = 0;

    virtual int getNumberOfNodesEvaluated() = 0;
};


#endif //MILESTONE3_SEARCHER_H
