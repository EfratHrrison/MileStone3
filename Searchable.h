//
// Created by neta on 1/8/19.
//
#ifndef MILESTONE3_SEARCHABLE_H
#define MILESTONE3_SEARCHABLE_H

#include "State.h"
#include <vector>
#include <string>
using namespace std;
template <class T>
class Searchable {
protected:
vector<State<T>*> searchable;
State<T>* initialState;
State<T>* goalState;
public:
    Searchable(vector<State<T>*> search, State<T>* initial, State<T>* goal){
        this->searchable=search;
        this->initialState=initial;
        this->goalState=goal;
    }
    virtual State<T>* getInitialState() = 0;

    virtual State<T>* getGoalState()=0;

    virtual vector<State<T>*> getAllPossibleStates(State<T>* s)=0;

    virtual string getPathSolution(vector<State<T>*> s)=0;
};

#endif //MILESTONE3_SEARCHABLE_H
