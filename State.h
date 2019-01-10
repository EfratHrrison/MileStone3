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
    int howManyNodes;
public:
    State(T state, double cost) : state(state), cost(cost) {
        this->cameFrom = nullptr;
        this->trailCost = 0;
        howManyNodes=0;
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

    T getState() {
        return state;
    }

    void setCost(double d) {
        this->cost = d;
    }

    double getTrailCost() {
        return this->trailCost;
    }

    void setHowManyNodes(int nodes) {
        this->howManyNodes = nodes;
    }

    int getHowManyNodes() {
        return this->howManyNodes;
    }


};
#endif //MILESTONE3_STATE_H
