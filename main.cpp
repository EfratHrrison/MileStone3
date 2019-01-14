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
 *  4, 2, 9, 5, 7, 0, 7, 6, 3, 7, 8 +
 4, 0,10, 8, 1, 0, 5, 5, 7, 8, 4  +
 4, 5, 2, 8, 1, 1, 9, 3, 3, 0, 7 +
 3, 3, 6, 2, 8, 9, 6, 8, 3, 5, 7 +
 0, 3, 7, 3, 7,10, 4, 8, 9, 1, 1 +
 7, 3, 2, 3, 5, 0, 2, 1, 6, 0, 9 +
 6, 9, 8, 1,10, 3, 9, 8, 3, 4, 8 +
10, 8, 0, 2, 3, 8, 0,10,10, 2, 7 +
 5, 7, 0, 8, 8, 8, 0, 3, 4, 5, 1 +
 7, 7, 5,10, 8,10, 1, 6, 9, 9, 1 +
 5,10, 1,10, 7, 7, 3,10, 8, 0, 6 +
 */

    State<Point> *initial = new State<Point>(Point(0, 0), 4);
    State<Point> *goal = new State<Point>(Point(10, 10), 6);
    vector<State<Point> *> searchable;
    searchable.push_back(initial);
    //  4, 2, 9, 5, 7, 0, 7, 6, 3, 7, 8
    searchable.push_back(new State<Point>(Point(0, 1), 2));
    searchable.push_back(new State<Point>(Point(0, 2), 9));
    searchable.push_back(new State<Point>(Point(0, 3), 5));
    searchable.push_back(new State<Point>(Point(0, 4), 7));
    searchable.push_back(new State<Point>(Point(0, 5), 0));
    searchable.push_back(new State<Point>(Point(0, 6), 7));
    searchable.push_back(new State<Point>(Point(0, 7), 6));
    searchable.push_back(new State<Point>(Point(0, 8), 3));
    searchable.push_back(new State<Point>(Point(0, 9), 7));
    searchable.push_back(new State<Point>(Point(0, 10), 8));
    // 4, 0,10, 8, 1, 0, 5, 5, 7, 8, 4
    searchable.push_back(new State<Point>(Point(1, 0), 4));
    searchable.push_back(new State<Point>(Point(1, 1), 0));
    searchable.push_back(new State<Point>(Point(1, 2), 10));
    searchable.push_back(new State<Point>(Point(1, 3), 8));
    searchable.push_back(new State<Point>(Point(1, 4), 1));
    searchable.push_back(new State<Point>(Point(1, 5), 0));
    searchable.push_back(new State<Point>(Point(1, 6), 5));
    searchable.push_back(new State<Point>(Point(1, 7), 5));
    searchable.push_back(new State<Point>(Point(1, 8), 7));
    searchable.push_back(new State<Point>(Point(1, 9), 8));
    searchable.push_back(new State<Point>(Point(1, 10), 4));
    //  4, 5, 2, 8, 1, 1, 9, 3, 3, 0, 7
    searchable.push_back(new State<Point>(Point(2, 0), 4));
    searchable.push_back(new State<Point>(Point(2, 1), 5));
    searchable.push_back(new State<Point>(Point(2, 2), 2));
    searchable.push_back(new State<Point>(Point(2, 3), 8));
    searchable.push_back(new State<Point>(Point(2, 4), 1));
    searchable.push_back(new State<Point>(Point(2, 5), 1));
    searchable.push_back(new State<Point>(Point(2, 6), 9));
    searchable.push_back(new State<Point>(Point(2, 7), 3));
    searchable.push_back(new State<Point>(Point(2, 8), 3));
    searchable.push_back(new State<Point>(Point(2, 9), 0));
    searchable.push_back(new State<Point>(Point(2, 10),7));
    //3, 3, 6, 2, 8, 9, 6, 8, 3, 5, 7
    searchable.push_back(new State<Point>(Point(3, 0), 3));
    searchable.push_back(new State<Point>(Point(3, 1), 3));
    searchable.push_back(new State<Point>(Point(3, 2), 6));
    searchable.push_back(new State<Point>(Point(3, 3), 2));
    searchable.push_back(new State<Point>(Point(3, 4), 8));
    searchable.push_back(new State<Point>(Point(3, 5), 9));
    searchable.push_back(new State<Point>(Point(3, 6), 6));
    searchable.push_back(new State<Point>(Point(3, 7), 8));
    searchable.push_back(new State<Point>(Point(3, 8), 3));
    searchable.push_back(new State<Point>(Point(3, 9), 5));
    searchable.push_back(new State<Point>(Point(3, 10),7));
    // 0, 3, 7, 3, 7,10, 4, 8, 9, 1, 1
    searchable.push_back(new State<Point>(Point(4, 0), 0));
    searchable.push_back(new State<Point>(Point(4, 1), 3));
    searchable.push_back(new State<Point>(Point(4, 2), 7));
    searchable.push_back(new State<Point>(Point(4, 3), 3));
    searchable.push_back(new State<Point>(Point(4, 4), 7));
    searchable.push_back(new State<Point>(Point(4, 5), 10));
    searchable.push_back(new State<Point>(Point(4, 6), 4));
    searchable.push_back(new State<Point>(Point(4, 7), 8));
    searchable.push_back(new State<Point>(Point(4, 8), 9));
    searchable.push_back(new State<Point>(Point(4, 9), 1));
    searchable.push_back(new State<Point>(Point(4, 10),1));
    // 7, 3, 2, 3, 5, 0, 2, 1, 6, 0, 9
    searchable.push_back(new State<Point>(Point(5, 0), 7));
    searchable.push_back(new State<Point>(Point(5, 1), 3));
    searchable.push_back(new State<Point>(Point(5, 2), 2));
    searchable.push_back(new State<Point>(Point(5, 3), 3));
    searchable.push_back(new State<Point>(Point(5, 4), 5));
    searchable.push_back(new State<Point>(Point(5, 5), 0));
    searchable.push_back(new State<Point>(Point(5, 6), 2));
    searchable.push_back(new State<Point>(Point(5, 7), 1));
    searchable.push_back(new State<Point>(Point(5, 8), 6));
    searchable.push_back(new State<Point>(Point(5, 9), 0));
    searchable.push_back(new State<Point>(Point(5, 10),9));
    // 6, 9, 8, 1,10, 3, 9, 8, 3, 4, 8
    searchable.push_back(new State<Point>(Point(6, 0), 6));
    searchable.push_back(new State<Point>(Point(6, 1), 9));
    searchable.push_back(new State<Point>(Point(6, 2), 8));
    searchable.push_back(new State<Point>(Point(6, 3), 1));
    searchable.push_back(new State<Point>(Point(6, 4), 10));
    searchable.push_back(new State<Point>(Point(6, 5), 3));
    searchable.push_back(new State<Point>(Point(6, 6), 9));
    searchable.push_back(new State<Point>(Point(6, 7), 8));
    searchable.push_back(new State<Point>(Point(6, 8), 3));
    searchable.push_back(new State<Point>(Point(6, 9), 4));
    searchable.push_back(new State<Point>(Point(6, 10),8));
    // 10, 8, 0, 2, 3, 8, 0,10,10, 2, 7
    searchable.push_back(new State<Point>(Point(7, 0), 10));
    searchable.push_back(new State<Point>(Point(7, 1), 8));
    searchable.push_back(new State<Point>(Point(7, 2), 0));
    searchable.push_back(new State<Point>(Point(7, 3), 2));
    searchable.push_back(new State<Point>(Point(7, 4), 3));
    searchable.push_back(new State<Point>(Point(7, 5), 8));
    searchable.push_back(new State<Point>(Point(7, 6), 0));
    searchable.push_back(new State<Point>(Point(7, 7), 10));
    searchable.push_back(new State<Point>(Point(7, 8), 10));
    searchable.push_back(new State<Point>(Point(7, 9), 2));
    searchable.push_back(new State<Point>(Point(7, 10),7));
    //  5, 7, 0, 8, 8, 8, 0, 3, 4, 5, 1
    searchable.push_back(new State<Point>(Point(8, 0), 5));
    searchable.push_back(new State<Point>(Point(8, 1), 7));
    searchable.push_back(new State<Point>(Point(8, 2), 0));
    searchable.push_back(new State<Point>(Point(8, 3), 8));
    searchable.push_back(new State<Point>(Point(8, 4), 8));
    searchable.push_back(new State<Point>(Point(8, 5), 8));
    searchable.push_back(new State<Point>(Point(8, 6), 0));
    searchable.push_back(new State<Point>(Point(8, 7), 3));
    searchable.push_back(new State<Point>(Point(8, 8), 4));
    searchable.push_back(new State<Point>(Point(8, 9), 5));
    searchable.push_back(new State<Point>(Point(8, 10),1));
    // 7, 7, 5,10, 8,10, 1, 6, 9, 9, 1
    searchable.push_back(new State<Point>(Point(9, 0), 7));
    searchable.push_back(new State<Point>(Point(9, 1), 7));
    searchable.push_back(new State<Point>(Point(9, 2), 5));
    searchable.push_back(new State<Point>(Point(9, 3), 10));
    searchable.push_back(new State<Point>(Point(9, 4), 8));
    searchable.push_back(new State<Point>(Point(9, 5), 10));
    searchable.push_back(new State<Point>(Point(9, 6), 1));
    searchable.push_back(new State<Point>(Point(9, 7), 6));
    searchable.push_back(new State<Point>(Point(9, 8), 9));
    searchable.push_back(new State<Point>(Point(9, 9), 9));
    searchable.push_back(new State<Point>(Point(9, 10),1));
    // 5,10, 1,10, 7, 7, 3,10, 8, 0, 6
    searchable.push_back(new State<Point>(Point(10, 0), 5));
    searchable.push_back(new State<Point>(Point(10, 1), 10));
    searchable.push_back(new State<Point>(Point(10, 2), 1));
    searchable.push_back(new State<Point>(Point(10, 3), 10));
    searchable.push_back(new State<Point>(Point(10, 4), 7));
    searchable.push_back(new State<Point>(Point(10, 5), 7));
    searchable.push_back(new State<Point>(Point(10, 6), 3));
    searchable.push_back(new State<Point>(Point(10, 7), 10));
    searchable.push_back(new State<Point>(Point(10, 8), 8));
    searchable.push_back(new State<Point>(Point(10, 9), 0));



    searchable.push_back(goal);
    Searchable<Point> *m = new Matrix(searchable, initial, goal);
    AStar<Point> *b = new AStar<Point>;
    string x = b->search(m);
    cout << x << endl;
    cout << b->getPathCost();

/*
    MySerialServer* d = new MySerialServer();
    Solver<Searchable<Point>*, string>* solver = new GetSolution(new BestFirstSearch<Point>());
    CacheManager* cacheManager = new FileCacheManager();
    ClientHandler* ds = new MyClientHandler(solver, cacheManager);
    d->open(5400,ds);
    while (true) {}
    return 0;
    */

}