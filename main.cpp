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


int main() {
//    vector<State<Point> *> searchable;
//    std::vector<std::vector<int>> matrix10(
//            {
//                    { 1,3, 1, 1, 1, 1, 0, 1, 1, 1 },
//                    { 1, 5, 1, 0, 1, 1, 1, 0, 1, 1 },
//                    { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
//                    { 0, 6, 0, 0, 1, 0, 0, 0, 0, 1 },
//                    { 1, 1, 1, 8, 1, 1, 1, 0, 1, 0 },
//                    { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
//                    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
//                    { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
//                    { 1, 1, 0, 0, 0, 0, 1, 0, 0, 1 },
//                    { 1, 1, 0, 0, 1, 0, 1, 0, 1, 0 }
//            });
//    for(int i=0; i<matrix10.size();++i){
//        searchable.push_back()
//    }
//
//    std::vector<std::vector<int>> matrix5(
//            {
//
//                    { 1, 0, 1, 1, 1 },
//                    { -1, 1, 1, 0, 3 },
//                    { 1, 0, 1, 1, 1 },
//                    { 1, 1, 0, -1, 4 },
//                    { 1, 1, 0, 0, 1 }
//            });
//
//    std::vector<std::vector<int>> maze(
//            {
//
//                    { 1, 2, 10, 10, 1 },
//                    { 1,20, 1, 0, 3 },
//                    { 1, 20, 2, 50, 1 },
//                    { 1, -1, 0, 30, 4 },
//                    { 1, 1, 0, 200, 1 }
//            });
//
//    std::vector<std::vector<int>> matrix3(
//            {
//                    { 1, 3, -1, 13 },
//                    { 1, 2, 1, 1 },
//                    { 1, -1, 1, 5 },
//            });
//
//    std::vector<std::vector<int>> matrix4(
//            {
//                    { 1, 3, 22, 13 },
//                    { 1, 2, 1, 1 },
//                    { 1, 0, 1, 5 },
//            });
//
//    std::vector<std::vector<int>> matrix2(
//            {
//                    { 1, -1 },
//                    { -1, 2 },
//            });
//



    MyParallelServer* d = new MyParallelServer();
    Solver<Searchable<Point>*, string>* solver = new GetSolution(new BestFirstSearch<Point>());
    CacheManager* cacheManager = new FileCacheManager();
    ClientHandler* ds = new MyClientHandler(solver, cacheManager);
    d->open(5400,ds);
    while (true) {}
    return 0;
}


