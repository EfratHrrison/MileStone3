//
// Created by efrat on 05/01/19.
//

#ifndef MILESTONE2_MYTESTCLIENTHANDLER_H
#define MILESTONE2_MYTESTCLIENTHANDLER_H
#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
#include <string>

class MyTestClientHandler : public ClientHandler {
    Solver <string,string> *solver;
    CacheManager<string,string> *cacheManager;
public:
    void handleClient(int clientSock) override;
};


#endif //MILESTONE2_MYTESTCLIENTHANDLER_H
