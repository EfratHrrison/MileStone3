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
    double trailCost;
    bool visited;
public:
    State(T* state, double cost) {
        this->state = state;
        this->visited = false;
        this->cameFrom = nullptr;
        this->cost = cost;
    }

    bool Equal(State *state1) {
        return (this->state==state1->state);
    }
    void setCameFrom(State<T>* dad) {
        this->cameFrom = dad;
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

    T* getState() {
        return state;
    }

    void setCost(double d) {
        this->cost = d;
    }

    double getTrailCost() {
        return this->trailCost;
    }

};
#endif //MILESTONE3_STATE_H
