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
    struct params {
        ClientHandler* clientHandler;
        int sockfd;
    };
    struct params *info = new params();
    int serverId;
    vector<pthread_t> threads;


public:
    void open(int port, ClientHandler *c) override;
    void stop() override;
    static void* parallelService (void* params);
    ~MyParallelServer() override {delete info;}
};



#endif //MILESTONE3_MYPARALLELSERVER_H
