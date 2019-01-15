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

//std::vector<std::vector<int>> generateMatrix(unsigned n){
//
//    vector<vector<int>> vec;
//
//    for (int k = 0; k < n; ++k) {
//        vector<int> curLine;
//        for (int i = 0; i < n; ++i) {
//            curLine.push_back(rand() % 10);
//        }
//        vec.push_back(curLine);
//    }
//
//    return vec;
//}
//
//void generateFiles() {
//
//    // min size
//    int n = 10;
//    for (int i = 1; i <= 5; i++) {
//        vector<std::vector<int>> matrix = generateMatrix(n);
//        Searchable<Point> *m = new Matrix(searchable, initial, goal);
//        AStar<Point> *b = new AStar<Point>;
//        string x = b->search(m);
//        cout << x << endl;
//        cout << b->getPathCost();
//        n += 4;
//    }
//
//}
//     searchable.push_back(new State<Point>(Point(4, 6), 4));

int main() {
//    vector<State<Point> *> searchable;
//    int i;
//    int j;
//    std::vector<std::vector<int>> matrix10(
//            {
//                    { 8, 0, 8, 6, 8, 2,10, 2, 4, 1, 9, 9, 5,10, 1, 1, 1, 0, 7, 3, 1, 6, 9, 3, 9, 7, 7, 9, 5, 6, 4, 5, 1, 6,-1, 1, 7},
//                            { 4,10, 2, 3, 0, 5, 2, 1,10, 2, 4, 5, 4, 3, 3, 4,10, 2, 3, 9, 6, 9, 1, 6, 7, 7, 5, 8, 7, 2,-1, 3, 2, 5,-1, 9, 2},
//                    {   1, 5, 8, 9, 0, 1, 2, 4, 7, 8, 2, 9, 8, 4, 2, 2,10, 8, 8, 2, 3, 3, 1, 5,10,-1, 2, 7, 1, 4,-1,-1,-1, 0,-1, 5, 6},
//                    {8, 6, 2, 4,10, 8, 9, 9, 7, 1, 0, 8, 8, 2, 4, 2, 1, 7, 6, 8, 3,-1, 8, 1, 8, 6, 1, 3, 3, 0, 7, 3, 4, 0, 9,10, 0},
//{    7, 6, 2,10, 7, 8, 1,-1, 5, 8, 8, 1, 1, 5, 8, 9, 9, 1, 8, 5, 1, 8, 4, 5, 4, 5, 8, 7, 6, 6, 8, 2, 0, 8, 8, 8, 8},
//{   9, 3, 0, 3, 5,10,-1, 9, 0, 8, 3, 8, 2,10,10, 7, 1, 8, 4, 2,10, 5, 4, 7, 4, 4, 6,10, 9, 0, 3, 5,10, 0, 0, 3, 5},
//{    10, 5, 1, 7, 5,10, 6, 6, 6, 5, 8, 9, 4, 3, 9, 0,10, 4, 9, 5, 3,10, 3, 9, 3, 4,-1, 8, 5, 0,10, 5, 2, 3, 7, 6,-1},
//{     1,10, 0, 9, 9, 1, 0, 2,-1, 0, 6,10, 1,10,10, 0, 7, 5, 2, 7, 7, 6, 9, 0, 3, 2, 4, 9,-1, 5, 7,-1, 9, 8, 6, 3, 4},
//{      10, 0, 1, 0, 6,10, 2, 6,-1,-1, 3, 9, 9, 8, 3, 7, 4, 3, 4, 5,-1, 9, 3, 5,10, 2, 3,-1,10, 2, 0, 0, 7, 8,-1,10, 2},
//{       7, 4, 8, 0, 8, 7,-1, 3,-1, 0,-1, 7, 9, 6, 7, 6, 1,10, 6, 0, 5, 8, 1, 2, 8, 3, 0,10, 7,10, 1, 2, 6, 9, 7, 3, 8},
//{        6, 0, 4, 7, 7,10, 8, 0, 1, 6, 2, 6, 4, 6, 6, 7, 5, 5, 8, 2,10, 2, 6, 8,10, 8,10, 9, 9, 0, 2, 0, 9, 6, 5, 4, 2},
//{    7, 0, 9, 4, 7, 4, 5, 8, 2, 2, 4, 3, 6, 1, 4, 7, 4, 9,-1, 5,10, 3, 4, 9, 7,10, 3, 5, 2, 9, 7, 0,-1, 5,10, 7, 1},
//{    6, 6, 8, 2,10, 4,-1, 4,-1, 2, 9, 6, 5, 7, 0, 4, 9,10, 4, 9, 0, 9, 2, 6, 7, 1,10, 5, 6, 6, 5,10, 4, 5, 7, 6, 8},
//{    3, 9, 1, 4, 8, 2,-1, 2,-1, 7, 8, 3, 6, 6, 9, 4, 6,-1, 4,-1, 1, 4, 5, 9, 2, 0, 1, 9, 3, 7, 0, 1,10, 5, 6,-1, 9},
//{   10, 8, 9, 1,10, 7, 0,10, 9,10,10, 1, 9, 3, 7, 5, 9, 3, 8, 6, 6, 7, 1, 1, 5, 6, 2, 7, 2, 3, 4, 9, 9, 9,10, 2, 8},
//{  10, 2, 8, 5,-1, 2, 5, 8, 7, 0, 5, 1, 3, 0, 4, 3, 9, 5, 9, 7, 7, 2,-1, 2, 8, 4, 1, 5, 9, 6, 0, 4, 0, 9, 1,-1, 0},
//{  4, 4, 5,10, 2, 5, 2, 3, 2, 2, 0, 4, 5, 3,10, 9, 3, 6, 2, 9, 9, 1, 4, 3, 2,10, 3, 1, 8, 6, 7, 4, 6, 7, 5, 1, 8},
//{   4,-1, 9, 7, 5, 5, 3,10, 8, 3, 3, 9, 5, 6, 1,10, 7, 4, 9, 9, 5, 9, 8, 9, 9, 1, 6, 9, 7, 5, 3, 5, 4, 6, 3, 0, 1},
//{    9, 0, 1, 5, 1, 3, 8, 0, 1, 2, 5, 0, 9, 9, 3, 4, 0, 2, 0,10, 7, 0,10, 3, 7, 0, 8, 9, 0, 1, 0, 2, 0, 3, 4,10, 3},
//{  6, 6, 1,-1,10, 7, 1, 5, 2, 3, 5, 8,10, 7, 3, 0, 6, 8, 5, 1,10, 0, 6, 6, 8, 0, 7,-1, 0, 7, 9, 5, 5, 7, 1, 5, 4},
//{   3, 6, 4,10, 7, 8, 2, 9, 8, 3, 4, 3, 8, 7, 6, 6, 2, 7, 9, 6, 6, 0, 0, 6, 5, 9, 2, 3, 3, 3,10, 7,10, 6, 7, 2, 9},
//{   10, 1, 2,-1, 7, 0, 5,10, 2, 8, 4, 7, 8, 7, 7, 5, 2, 5, 7, 4, 2, 4, 3,10, 6, 8, 5, 2, 1, 4, 9, 0, 1, 4, 0, 2, 2},
//{    10, 4, 9,10, 9,10, 9,10, 7, 9, 0, 1, 6, 5, 3, 0, 6, 4, 7, 9,10, 4, 4, 9, 8, 1, 7, 8, 0, 0, 9, 3, 8, 5, 3, 7, 6},
//{    7, 4, 6, 0, 7, 7, 8, 6, 8, 9, 1, 2, 9, 3, 4, 9, 0, 8,10, 1, 0, 5, 9, 8, 7, 9, 3, 3,10, 7, 9, 8, 3, 2,10, 3, 6},
//{     9, 2, 1, 8, 4, 8, 1, 8, 6, 0, 3, 9, 1, 7, 3, 8, 5, 8, 5, 4, 4,10, 5, 0, 9, 2, 1, 9, 0, 6, 8, 4, 4,-1,-1,-1,10},
//{     7, 7, 0, 8, 4, 4, 1, 9, 8, 0, 9, 8,10, 5, 5, 2, 8, 1, 5, 9, 9,10, 6, 5, 9, 8, 1, 4, 4, 7, 6,10, 4, 9, 1, 8, 2},
//{      1, 6, 7, 2, 8, 7, 6,10, 1, 0, 9, 5,10, 7, 6, 4, 9, 2, 2, 5, 1, 9, 2, 1, 6, 8, 3, 0, 8, 1, 0, 6, 9, 8, 3,-1, 0},
//{        5, 5, 7,10, 1, 8, 4, 4, 0,10,10, 1, 1, 2, 8, 4, 8, 0, 6, 8, 3, 8, 5, 5, 3, 8,10, 8, 5,10, 1,10, 2, 5, 0,-1, 6},
//{        9, 0, 8, 1, 3, 5, 6, 0, 7, 9, 2, 1, 6, 8, 1, 2, 1, 5, 0, 0,10, 0, 4, 9, 0, 0, 4, 7, 4, 3, 6, 9, 6, 5,10, 0, 3},
//{                   1, 7, 2, 0, 5, 6,10, 6, 6,10,10, 2, 1, 0, 2, 7, 1, 1, 8, 3, 5, 0,10, 1, 8, 2, 6, 3, 0, 9, 3, 2, 4, 9, 8, 5, 3},
//{                   1, 3, 2, 1, 1, 6, 3,-1, 0, 4, 8, 7, 3, 4, 7, 6, 1, 9, 7, 0,10, 4, 6, 5, 7, 8, 2,10, 1, 2, 6, 7, 8, 2, 3,10, 9},
//{                   3, 6, 4, 9, 2,10, 9, 8, 2, 7, 6, 6, 8, 3, 7, 9, 3, 7, 0, 0, 3, 2, 4, 5, 8, 7, 2,10,10, 4,10, 2,10,-1, 6,-1, 0},
//{                   6, 4, 4,10, 8, 3, 0, 7, 3, 8, 4, 7, 3, 1, 5, 6, 0, 2, 2, 6, 2, 1, 4, 3, 1, 4, 0, 5, 7, 1, 6, 5,10, 7, 5,-1, 3},
//{ 4, 8, 0, 2,10, 9, 3, 3, 8, 7, 7, 8,10, 6,10, 2, 4,10, 0,10, 7, 8, 7, 1, 9, 5,10, 4, 2, 0, 9, 7, 1, 8, 3, 8, 9},
//{ 2, 2, 5, 1, 7, 1, 8, 2,10, 3,10, 5, 7, 9,10,10,10, 0, 4, 4, 2,10, 2, 0, 1, 6, 9,10, 7, 4, 6,10, 8, 4, 8, 0,10},
//{ 3, 1, 0, 8, 1, 4, 7, 9, 3, 7, 3, 6, 6, 6, 3, 9, 9, 3, 9, 3, 3, 7, 5,10, 0, 8, 2, 2, 5, 4, 9, 8, 5, 3, 2, 6, 4},
//{10, 1, 9, 5, 9, 2, 6,10, 3, 4,10,-1,10, 7, 9, 2, 1, 2, 0, 4, 6,10, 2, 0, 0, 3, 4, 1, 4, 4, 0, 4,10, 6, 2, 5, 6}
//            });
//
//    for(i=0; i<matrix10.size();++i) {
//        for (j=0;j<matrix10[0].size();++j) {
//            searchable.push_back(new State<Point>(Point(i, j), matrix10.at(i).at(j)));
//        }
//    }
//    State<Point> *initial = new State<Point>(Point(0, 0), 1);
//    State<Point> *goal = new State<Point>(Point(i-1, j-1), matrix10.at(i-1).at(j-1));
//    Searchable<Point> *m = new Matrix(searchable, initial, goal);
//    BestFirstSearch<Point> *b = new BestFirstSearch<Point>;
//    string x = b->search(m);
//    cout << x << endl;
//    cout << b->getPathCost()<< endl;;
//    searchable.clear();
//    ///////////////////////////////////////////////////////////
//    std::vector<std::vector<int>> matrix5({
//                    { 1, 0, 1, 1, 1 },
//                    {5, 1, 1, 0, 3 },
//                    { 1, 0, 1, 1, 1 },
//                    { 1, 1, 0, 7, 4 },
//                    { 1, 1, 0, 0, 1 }
//            });
//    for(i=0; i<matrix5.size();++i) {
//        for (j=0;j<matrix5[0].size();++j) {
//            searchable.push_back(new State<Point>(Point(i, j), matrix5.at(i).at(j)));
//        }
//    }
//    State<Point> *initial1 = new State<Point>(Point(0, 0), 1);
//    State<Point> *goal1 = new State<Point>(Point(i-1, j-1), matrix5.at(i-1).at(j-1));
//    Searchable<Point> *m1 = new Matrix(searchable, initial1, goal1);
//    BestFirstSearch<Point> *b1 = new BestFirstSearch<Point>;
//    string x1 = b1->search(m);
//    cout << x1 << endl;
//    cout << b1->getPathCost()<< endl;;;
//    searchable.clear();
//    ///////////////////////////////////////////////////////////////////////////////
//    std::vector<std::vector<int>> maze(
//            {
//
//                    { 1, 2, 10, 10, 1 },
//                    { 1,20, 1, 0, 3 },
//                    { 1, 20, 2, 50, 1 },
//                    { 1, 8, 0, 30, 4 },
//                    { 1, 1, 0, 200, 1 }
//            });
//    for(i=0; i<maze.size();++i) {
//        for (j=0;j<maze[0].size();++j) {
//            searchable.push_back(new State<Point>(Point(i, j), maze.at(i).at(j)));
//        }
//    }
//    State<Point> *initial2 = new State<Point>(Point(0, 0), 1);
//    State<Point> *goal2 = new State<Point>(Point(i-1, j-1), maze.at(i-1).at(j-1));
//    Searchable<Point> *m2 = new Matrix(searchable, initial2, goal2);
//    BestFirstSearch<Point> *b2 = new BestFirstSearch<Point>;
//    string x2 = b2->search(m2);
//    cout << x2 << endl;
//    cout << b2->getPathCost()<< endl;;;
//    searchable.clear();
///////////////////////////////////////////////////////////////////////////////
//    std::vector<std::vector<int>> matrix3(
//            {
//                    { 1, 3, 2, 13 },
//                    { 1, 2, 1, 1 },
//                    { 1, 2, 1, 5 },
//            });
//    for(i=0; i<matrix3.size();++i) {
//        for (j=0;j<matrix3[0].size();++j) {
//            searchable.push_back(new State<Point>(Point(i, j), matrix3.at(i).at(j)));
//        }
//    }
//    State<Point> *initial3 = new State<Point>(Point(0, 0), 1);
//    State<Point> *goal3 = new State<Point>(Point(i-1, j-1), matrix3.at(i-1).at(j-1));
//    Searchable<Point> *m3 = new Matrix(searchable, initial3, goal3);
//    BestFirstSearch<Point> *b3 = new BestFirstSearch<Point>;
//    string x3 = b3->search(m3);
//    cout << x3 << endl;
//    cout << b3->getPathCost()<< endl;;;
//    searchable.clear();
//    /////////////////////////////////////////////////////////////////////////////////
//
//    std::vector<std::vector<int>> matrix4(
//            {
//                    { 1, 3, 22, 13 },
//                    { 1, 2, 1, 1 },
//                    { 1, 6, 1, 5 },
//            });
//    for(i=0; i<matrix4.size();++i) {
//        for (j=0;j<matrix4[0].size();++j) {
//            searchable.push_back(new State<Point>(Point(i, j), matrix4.at(i).at(j)));
//        }
//    }
//    State<Point> *initial4 = new State<Point>(Point(0, 0), 1);
//    State<Point> *goal4 = new State<Point>(Point(i-1, j-1), matrix4.at(i-1).at(j-1));
//    Searchable<Point> *m4 = new Matrix(searchable, initial4, goal4);
//    BestFirstSearch<Point> *b4 = new BestFirstSearch<Point>;
//    string x4 = b4->search(m4);
//    cout << x4 << endl;
//    cout << b4->getPathCost()<< endl;;
//    searchable.clear();
//    //////////////////////////////////////////////////////////////////////////////////
//    std::vector<std::vector<int>> matrix2(
//            {
//                    { 1, 10 },
//                    { 1, 2 },
//            });
//
//    for(i=0; i<matrix2.size();++i) {
//        for (j=0;j<matrix2[0].size();++j) {
//            searchable.push_back(new State<Point>(Point(i, j), matrix2.at(i).at(j)));
//        }
//    }
//    State<Point> *initial5 = new State<Point>(Point(0, 0), 1);
//    State<Point> *goal5 = new State<Point>(Point(i-1, j-1), matrix2.at(i-1).at(j-1));
//    Searchable<Point> *m5 = new Matrix(searchable, initial5, goal5);
//    BestFirstSearch<Point> *b5 = new BestFirstSearch<Point>;
//    string x5 = b5->search(m5);
//    cout << x5 << endl;
//    cout << b5->getPathCost()<< endl;;


    MyParallelServer* d = new MyParallelServer();
    Solver<Searchable<Point>*, string>* solver = new GetSolution(new BestFirstSearch<Point>());
    CacheManager* cacheManager = new FileCacheManager();
    ClientHandler* ds = new MyClientHandler(solver, cacheManager);
    d->open(5400,ds);
    while (true) {}
    return 0;

//    State<Point>* initial = new State<Point>(Point(0, 0), 3);
//    State<Point>* goal = new State<Point>(Point(2, 2), 6);
//
//    vector<State<Point> *> searchable;
//    searchable.push_back(initial);
//    searchable.push_back(new State<Point>(Point(0, 1), -1));
//    searchable.push_back(new State<Point>(Point(0, 2), 2));
//    searchable.push_back(new State<Point>(Point(1, 0), 1));
//    searchable.push_back(new State<Point>(Point(1, 1), 7));
//    searchable.push_back(new State<Point>(Point(1, 2), 5));
//    searchable.push_back(new State<Point>(Point(2, 0), 100));
//    searchable.push_back(new State<Point>(Point(2, 1), 4));
//    searchable.push_back(goal);
//
//
//    Searchable<Point>* m = new Matrix(searchable, initial, goal);
//    AStar<Point> * b = new AStar<Point>;
//    string x = b->search(m);
//    cout << x << endl;


}


