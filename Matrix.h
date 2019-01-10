//
// Created by neta on 1/9/19.
//

#ifndef MILESTONE3_MATRIX_H
#define MILESTONE3_MATRIX_H

#include "string"
#include "Point.h"
#include "Searchable.h"

class Matrix : public Searchable<class Point> {
    //State<Point>* InitialState;
    //vector<State<Point>*> vector1;
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

};


#endif //MILESTONE3_MATRIX_H
