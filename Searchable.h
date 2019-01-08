//
// Created by neta on 1/8/19.
//
#ifndef MILESTONE3_SEARCHABLE_H
#define MILESTONE3_SEARCHABLE_H

#include "State.h"
#include <vector>
using namespace std;
template <class T>

class Searchable {
public:

    virtual State<T>* getInitialState() = 0;

    virtual State<T>* getGoalState()=0;

    virtual vector<State<T>*> getAllPossibleStates(State<T> s)=0;
};

#endif //MILESTONE3_SEARCHABLE_H
