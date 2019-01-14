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
#define NO_PATH "-1";

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
            //If n is the goal state
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
            //Create n's successors
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
    int getNumberOfNodesEvaluated() override {
        return evaluated;
    }
    /**
        * this func returns the cost of the path we made
        * @return the cost of our path
        */
    double getPathCost() override {
        return pathCost;
    }

};

#endif //MILESTONE3_BESTFIRSTSEARCH_H