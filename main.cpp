#include <iostream>
#include "FileCachManager.h"
#include "MySerialServer.h"
#include "MyClientHandler.h"
#include "Solver.h"
#include "BestFirstSearch.h"
#include "Matrix.h"
#include "State.h"
#include "Point.h"
#include "BFS.h"

#include "Astar.h"
#include "DFS.h"
#include "MyParallelServer.h"
#include "GetSolution.h"


int main() {
/*
    MyParallelServer* d = new MyParallelServer();
    Solver<Searchable<Point>*, string>* solver = new GetSolution(new BestFirstSearch<Point>());
    CacheManager* cacheManager = new FileCacheManager();
    ClientHandler* ds = new MyClientHandler(solver, cacheManager);
    d->open(5400,ds);
    while (true) {}
    return 0;
    */

    State<Point>* initial = new State<Point>(Point(0, 0), 7);
    State<Point>* goal = new State<Point>(Point(4, 4), 3);

    vector<State<Point> *> searchable;
    searchable.push_back(initial);
    searchable.push_back(new State<Point>(Point(0, 1), 4));
    searchable.push_back(new State<Point>(Point(0, 2), 8));
    searchable.push_back(new State<Point>(Point(0, 3), 5));
    searchable.push_back(new State<Point>(Point(0, 4), 20));

    searchable.push_back(new State<Point>(Point(1, 0), 15));
    searchable.push_back(new State<Point>(Point(1, 1), 18));
    searchable.push_back(new State<Point>(Point(1, 2), 10));
    searchable.push_back(new State<Point>(Point(1, 3), 20));
    searchable.push_back(new State<Point>(Point(1, 4), 18));

    searchable.push_back(new State<Point>(Point(2, 0), 7));
    searchable.push_back(new State<Point>(Point(2, 1), 21));
    searchable.push_back(new State<Point>(Point(2, 2), 5));
    searchable.push_back(new State<Point>(Point(2, 3), 6));
    searchable.push_back(new State<Point>(Point(2, 4), 21));

    searchable.push_back(new State<Point>(Point(3, 0), 20));
    searchable.push_back(new State<Point>(Point(3, 1), 16));
    searchable.push_back(new State<Point>(Point(3, 2), 9));
    searchable.push_back(new State<Point>(Point(3, 3), 12));
    searchable.push_back(new State<Point>(Point(3, 4), 8));

    searchable.push_back(new State<Point>(Point(4, 0), 2));
    searchable.push_back(new State<Point>(Point(4, 1), 7));
    searchable.push_back(new State<Point>(Point(4, 2), 3));
    searchable.push_back(new State<Point>(Point(4, 3), 19));

    searchable.push_back(goal);

    Searchable<Point>* m = new Matrix(searchable, initial, goal);
    DFS<Point> * b = new DFS<Point>;
   string x = b->search(m);
   cout << x << endl;
   cout << b->getPathCost();


}


