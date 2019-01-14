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
//class Point;

template <class T>
class AStar :  public Searcher<Point> {
private:
    int evaluated;
    double pathCost;
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
    bool isExist( priority_queue<State<T> *, vector<State<T> *>, Cmp> open, State<T> *state) {
        while (!open.empty()) {
            if (state->Equal(open.top())) {
                return true;
            }
            open.pop();
        }
        return false;
    }
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
        evaluated++;
        bool foundDest = false;

        while (!openList.empty()) {
            State<T> *n = openList.top();
            openList.pop();
            evaluated++;
            n->setVisited();
            closed.insert(n);
            if (n->Equal(searchable->getGoalState())) {
                evaluated++;
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
                finalPath= searchable->getPathSolution(back);
                return finalPath;
            }
            vector<State<T> *> adjacent = searchable->getAllPossibleStates(n);
            for (State<T> *adj : adjacent) {
                bool exist = isExist(openList, adj);
                if (!exist && closed.count(adj) != 1) {
                    adj->setCameFrom(n);
                    adj->setHeur(this->calculateHValue(adj, searchable));
                    openList.push(adj);
                    adj->setDistance(n->getDistance() + adj->getCost());

                } else if (adj->getDistance() > n->getDistance() + adj->getCost()) {
                    bool inOpen = isExist(openList, adj);
                    adj->setDistance(n->getDistance() + adj->getCost());
                    adj->setCameFrom(n);
                    adj->setHeur(this->calculateHValue(adj, searchable));
                    openList = updateQueue(openList);
                }
            }
        }
    }

    int getNumberOfNodesEvaluated()
    override{
        return 0;
    }

    double getPathCost() {
        return pathCost;
    }

};
#endif //MILESTONE3_ASTAR_H
