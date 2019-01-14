//
// Created by neta on 1/8/19.
//

#ifndef MILESTONE3_BESTFIRSTSEARCH_H
#define MILESTONE3_BESTFIRSTSEARCH_H
#include <algorithm>
#include "Searcher.h"
#include <queue>
#include "iostream"
#include <unordered_set>
#include "Searcher.h"
#include "list"
#include <unordered_set>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

template<class T>
class BestFirstSearch : public Searcher<T> {
private:
    int evaluated;
    double pathCost;
    class Cmp {
    public:
        bool operator()(State<T>* left, State<T>* right) {
            return (left->getDistance()) > (right->getDistance());
        }
    };

public:
    BestFirstSearch() {
        evaluated = 0;
        pathCost =0;
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

    string search(Searchable<T>* searchable) override {
        priority_queue<State<T>*, vector<State<T>*>, Cmp> openList;
        openList.push(searchable->getInitialState());
        unordered_set<State<T>*> closed;
        string finalPath="";
        vector<State<T>*> path;
        while (!openList.empty()) {
            evaluated++;
            State<T>* n = openList.top();
            openList.pop();
            closed.insert(n);
            if (n->Equal(searchable->getGoalState())) {
                path.push_back(n);
                while (!n->Equal(searchable->getInitialState())) {
                    path.push_back(n->getDad());
                    pathCost += n->getCost();
                    n = n->getDad();
                }
                pathCost += n->getCost();
                vector<State<T>*> back;
                for (int i = path.size() - 1; i >= 0 ; i--) {
                    back.push_back(path.at(i));
                }
                finalPath= searchable->getPathSolution(back);
                return finalPath;
            }
            vector<State<T> *> neighbors = searchable->getAllPossibleStates(n);
            for (State<T>* adj : neighbors) { ;
                bool exist = isExist(openList, adj);
                if (!exist && closed.count(adj) != 1) {
                    adj->setCameFrom(n);
                    adj->setDistance(n->getDistance());
                    openList.push(adj);
                } else if (adj->getDistance() > n->getDistance() + adj->getCost()) {
                    bool inOpen = isExist(openList, adj);
                    adj->setDistance(n->getDistance() + adj->getCost());
                    adj->setCameFrom(n);
                    openList = updateQueue(openList);
                }
            }
        }
        return finalPath;
    }

    int getNumberOfNodesEvaluated() override {
        return evaluated;
    }

    double getPathCost() override {
        return pathCost;
    }

};

#endif //MILESTONE3_BESTFIRSTSEARCH_H