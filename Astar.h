//
// Created by efrat on 13/01/19.
//

#ifndef MILESTONE3_ASTAR_H
#define MILESTONE3_ASTAR_H
#include "Searcher.h"
#include <unordered_set>
#include <vector>
#include <queue>
#include "Point.h"
#include <algorithm>
#define NO_PATH "-1";
//class Point;

template <class T>
class AStar :  public Searcher<Point> {
private:
    int evaluated;
    double pathCost;
    //compare for the priority_queue that will sort the wight from the lowest
    class Cmp {
    public:
        bool operator()(State<Point>* left, State<Point>* right) {
            return (left->getHeur()) > (right->getHeur());
        }
    };

public:
    AStar() {
        evaluated = 0;
        pathCost = 0;
    }
    /**
     * this function calculate the heuristics func for the a star algorithm
     * @param cur - our current state
     * @param searchable - our goal state
     * @return the double that the func calculate based on manhattan heuristics
     */
    double calculateHValue(State<Point>* cur,Searchable<Point> *searchable) {
        State<Point>* goal = searchable->getGoalState();
        int xCur = cur->getState().getX();
        int yCur = cur->getState().getY();
        int xGoal = searchable->getGoalState()->getState().getX();
        int yGoal = searchable->getGoalState()->getState().getY();
        double disMan = abs (xCur - xGoal) +
                        abs (yCur - yGoal);
        double total = disMan + cur->getCost() + cur->getDad()->getDistance();
        return total;

    }
    /**
     * this function checks if a state is already in our queue
     * @param open - our priority_queue
     * @param state - the state we a looking for
     * @return true if the state in the priority_queue false otherwise
     */
    bool isExist( priority_queue<State<T> *, vector<State<T> *>, Cmp> open, State<T> *state) {
        while (!open.empty()) {
            if (state->Equal(open.top())) {
                return true;
            }
            open.pop();
        }
        return false;
    }
    /**
     * this func updates the priority_queue when we want to update the cost for one of the states
     * @param queueOpen
     * @return the new priority_queue after we apdated it
     */
    priority_queue<State<T>*,vector<State<T>*>,Cmp> updateQueue(priority_queue<State<T>*, vector<State<T>*>, Cmp> &queueOpen) {
        priority_queue<State<T>*,vector<State<T>*>,Cmp> temp;
        while (!queueOpen.empty()) {
            State<T>* node = queueOpen.top();
            temp.push(node);
            queueOpen.pop();
        }
        return temp;
    }
    string search(Searchable<T> *searchable) override {
        priority_queue<State<T> *, vector<State<T> *>, Cmp> openList;
        priority_queue<State<T> * ,vector<State<T> *> , Cmp> open;
        openList.push(searchable->getInitialState());
        unordered_set<State<T> *> closed;
        vector<State<T> *> path;
        string finalPath="";
        openList.push(searchable->getInitialState());
        bool foundDest = false;

        while (!openList.empty()) {
            State<T> *n = openList.top();
            openList.pop();
            evaluated++;
            n->setVisited();
            closed.insert(n);
            //If n is the goal state
            if (n->Equal(searchable->getGoalState())) {
                //backtrace path to n (through recorded parents) and return path
                path.push_back(n);
                while (!n->Equal(searchable->getInitialState())) {
                    path.push_back(n->getDad());
                    pathCost += n->getCost();
                    n = n->getDad();
                }
                pathCost += n->getCost();
                vector<State<T> *> back;
                for (int i = path.size() - 1; i >= 0; i--) {
                    back.push_back(path.at(i));
                }
                //get the final path
                finalPath= searchable->getPathSolution(back);
                return finalPath;
            }
            //Create n's successors
            vector<State<T> *> adjacent = searchable->getAllPossibleStates(n);
            for (State<T> *adj : adjacent) {
                bool exist = isExist(openList, adj);
                //If s is not in CLOSED and s is not in OPEN
                if (!exist && closed.count(adj) != 1) {
                    //update that we came to s from n
                    adj->setCameFrom(n);
                    adj->setHeur(this->calculateHValue(adj, searchable));
                    openList.push(adj);
                    adj->setDistance(n->getDistance() + adj->getCost());
                   //Otherwise, if this new path is better than previous one
                } else if (adj->getDistance() > n->getDistance() + adj->getCost()) {
                    bool inOpen = isExist(openList, adj);
                    adj->setDistance(n->getDistance() + adj->getCost());
                    adj->setCameFrom(n);
                    adj->setHeur(this->calculateHValue(adj, searchable));
                    //Otherwise, adjust its priority in OPEN done
                    openList = updateQueue(openList);
                }
            }
        }
        //dead end -  which means we run into "walls" so there is no path
        return NO_PATH;
    }

    /**
     * this function returns the number of nodes we evaluated in our algotithm
     * @return num of nodes
     */
    int getNumberOfNodesEvaluated()
    override{
        return evaluated;
    }
    /**
     * this func returns the cost of the path we made
     * @return the cost of our path
     */
    double getPathCost() {
        return pathCost;
    }

};
#endif //MILESTONE3_ASTAR_H
