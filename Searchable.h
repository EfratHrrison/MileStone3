//
// Created by neta on 1/8/19.
//
#ifndef MILESTONE3_SEARCHABLE_H
#define MILESTONE3_SEARCHABLE_H

#include "string"
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
double allCost;
public:
    Searchable(vector<State<T>*> search, State<T>* initial, State<T>* goal) {
        this->searchable=search;
        this->initialState=initial;
        this->goalState=goal;
        this->allCost=0;
    }
    const vector<State<T> *> &getSearchable() const {
        return this->searchable;
    }
    virtual State<T>* getInitialState() = 0;

    virtual State<T>* getGoalState() = 0;

    virtual vector<State<T>*> getAllPossibleStates(State<T>* s) = 0;

    virtual string getPathSolution(vector<State<T>*> s) = 0;

    virtual void setAllCost(double number) = 0;

    virtual double getAllCOst() = 0;

    virtual ~Searchable() = default;
};

#endif //MILESTONE3_SEARCHABLE_H
