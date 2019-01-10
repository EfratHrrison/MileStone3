//
// Created by neta on 1/9/19.
//
#include "string"
#include "Matrix.h"

vector<State<Point>*> Matrix::getAllPossibleStates(State<Point>* s){
    vector<State<Point>*> neighbors;
    int i = s->getState().getX();
    int j = s->getState().getY();
    for (int n = 0; n < this->searchable.size(); ++n) {
        int n1 = this->searchable[n]->getState().getX();
        int n2 = this->searchable[n]->getState().getY();
        if (((n1 == (i - 1)) && (n2 == j)) || ((n1 == (i + 1)) && (n2 == j))
            || ((n1 == i) && (n2 == (j - 1))) || ((n1 == i) && (n2 == (j + 1)))) {
            if (this->searchable[n]->getCost() != (-1)) {
                neighbors.push_back(this->searchable[n]);
            }
        }
    }
    return neighbors;
}

string Matrix::getPathSolution(vector<State<Point>*> pathPoints){
    State<Point>* s;
    State<Point>* next;
    string finalPath="{";
    for(int i=0; i<pathPoints.size()-1; i++) {
        s = pathPoints[i];
        next=pathPoints[i+1];
        int xNext=next->getState().getX();
        int yNext=next->getState().getY();
        int X = s->getState().getX();
        int Y = s->getState().getY();
        if (xNext==X+1){
            finalPath+="Down, ";
        }
        else if(xNext==X-1){
            finalPath+="Up, ";
        }
        else if (yNext==Y-1){
            finalPath+="Left, ";
        }
        else if (yNext==Y+1){
            finalPath+="Right, ";
        }
    }
    finalPath.erase(finalPath.size()-2);
    finalPath+="}";
    return finalPath;
}
