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
    struct dataPass *passingData = new dataPass();
    vector<pthread_t> threadList;
    int port;
    int sockfd;
    int serverfd;
    vector <pthread_t> threads;
public:
    void open(int port, ClientHandler *cH);

    void stop();

    static void* threadManager (void* data);



};



#endif //MILESTONE3_MYPARALLELSERVER_H
