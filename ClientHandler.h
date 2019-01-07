//
// Created by efrat on 05/01/19.
//

#ifndef MILESTONE2_CLIENTHANDLER_H
#define MILESTONE2_CLIENTHANDLER_H

#include <iostream>
#include <ostream>
#include "CacheManager.h"
using namespace std;
class ClientHandler {

public:

    virtual void handleClient(int clientSock) = 0;
};


#endif //MILESTONE2_CLIENTHANDLER_H
