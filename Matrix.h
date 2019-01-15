//
// Created by neta on 1/9/19.
//

#ifndef MILESTONE3_MATRIX_H
#define MILESTONE3_MATRIX_H

#include "string"
#include "Point.h"
#include "Searchable.h"
#include <string>

class Matrix : public Searchable<class Point> {
public:
    Matrix(vector<State<Point>*> search, State<Point>* initial, State<Point>* goal)
    : Searchable(search, initial,goal){
    }


    State<Point>* getInitialState() {
        return this->initialState;
    }

    void setInitialState(State<Point>* point) {
        this->initialState=point;
    }

    State<Point>* getGoalState(){
        return this->goalState;
    }

    vector<State<Point>*> getAllPossibleStates(State<Point>* s);

    string getPathSolution(vector<State<Point>*> pathPoints);

    void setAllCost(double number);

    double getAllCOst();

    ~Matrix(){
        for (auto point: searchable){
            delete point;
        }
    }

};


#endif //MILESTONE3_MATRIX_H
