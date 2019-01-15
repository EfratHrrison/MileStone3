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



namespace boot {
    class Main {
    public:
        int main(int argc, char *argv[]) {
            return 0;
        }
    };
}

int main(int argc, char *argv[]) {
    boot::Main main1;
    main1.main(argc, argv);
    server_side::Server *d = new MyParallelServer();
    Solver<Searchable<Point> *, string> *solver = new GetSolution(new AStar<Point>());
    CacheManager *cacheManager = new FileCacheManager();
    ClientHandler *ds = new MyClientHandler(solver, cacheManager);
    d->open(stoi(argv[1]), ds);
    delete (d);
    delete (solver);
    delete (cacheManager);
    delete (ds);
    return 0;
}