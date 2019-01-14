//
// Created by neta on 1/13/19.
//

#ifndef MILESTONE3_MYPARALLELSERVER_H
#define MILESTONE3_MYPARALLELSERVER_H
#include <netinet/in.h>
#include <strings.h>
#include <unistd.h>
#include <thread>
#include "Server.h"
#include "MyClientHandler.h"

class MyParallelServer : public server_side::Server {
private:
    vector<pthread_t> threads;
    struct params {
        ClientHandler* clientHandler;
        int sockfd;
    };

public:
    void open(int port, ClientHandler *c);
    void stop();
    static void* parallelService (void* params);
};



#endif //MILESTONE3_MYPARALLELSERVER_H
