//
// Created by neta on 1/8/19.
//

#ifndef MILESTONE3_SEARCHER_H
#define MILESTONE3_SEARCHER_H
#include <string>
#include "Searchable.h"
#include "vector"

using namespace std;

template <class T>

class Searcher {
public:
    virtual string search (Searchable<T>* searchable) = 0;

    virtual int getNumberOfNodesEvaluated() = 0;

    virtual double getPathCost() = 0;
};


#endif //MILESTONE3_SEARCHER_H
