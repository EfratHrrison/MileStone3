//
// Created by efrat on 05/01/19.
//

#ifndef MILESTONE2_MYTESTCLIENTHANDLER_H
#define MILESTONE2_MYTESTCLIENTHANDLER_H
#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
#include "State.h"
#include <string>
#include <vector>
#include "Point.h"
#include "Searchable.h"

class MyClientHandler : public ClientHandler {
    Solver <Searchable<Point>*,string> *solver;
    CacheManager *cacheManager;
public:
    MyClientHandler(Solver<Searchable<Point>*, string>* solver, CacheManager* cacheManager) {
        this->solver = solver;
        this->cacheManager = cacheManager;
    }
    void handleClient(int clientSock) override;
    vector<string> explode(string& s, const char& c);

    State<Point>* getStatePoint(vector<State<Point>*> searchable, Point initial);
};


#endif //MILESTONE2_MYTESTCLIENTHANDLER_H
