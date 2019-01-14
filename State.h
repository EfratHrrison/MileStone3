//
// Created by neta on 1/8/19.
//

#ifndef MILESTONE3_STATE_H
#define MILESTONE3_STATE_H

template <class T>
class State {
private:
    T state;
    double cost;
    State<T>* cameFrom;
    double distance;
    double trailCost;
    bool visited;
    double heur;

public:
    double totalCost;
    State(T state, double cost) : state(state), cost(cost) {
        this->cameFrom = nullptr;
        this->distance=cost;
        this->trailCost = 0;
        totalCost=0;
        this->heur=0;
    }
    bool Equal(State *state1) {
        return (this->state==state1->state);
    }
    void setCameFrom(State<T>* dad) {
        this->cameFrom = dad;
    }

    void setDistance(double d) {
        this->distance += d;
    }

    double getDistance() {
        return distance;
    }

    void setVisited() {
        this->visited = true;
    }

    bool ifVisited() {
        return this->visited;
    }

    State<T>* getDad() {
        return this->cameFrom;
    }

    double getCost() {
        return this->cost;
    }

    T getState() {
        return state;
    }

    double getHeur() {
        return heur;
    }

    void setHeur(double heur) {
        this->heur = heur;
    }




};
#endif //MILESTONE3_STATE_H
