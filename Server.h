//
// Created by efrat on 05/01/19.
//

#ifndef MILESTONE2_SERVER_H
#define MILESTONE2_SERVER_H
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <thread>

#include "ClientHandler.h"

namespace server_side {
    class Server {

    public:
        virtual void open(int port, ClientHandler *c) = 0;

        virtual void stop() = 0;

        virtual ~ Server() = default;
    };
}


#endif //MILESTONE2_SERVER_H
