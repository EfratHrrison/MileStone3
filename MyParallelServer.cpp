#include <sys/socket.h>
#include <netinet/in.h>
#include <cstdlib>
#include <strings.h>
#include <cstdio>
#include <thread>
#include <iostream>
#include <unistd.h>
#include <bits/sigthread.h>
#include "MyParallelServer.h"
#include <stack>

void MyParallelServer::open(int port, ClientHandler *cH) {
    int portno;
    int clilen, cliSock;
    struct sockaddr_in cli_addr;
    struct sockaddr_in serv_addr;

    /* First call to socket() function */
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    info->clientHandler = cH;
    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = port;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }
    listen(sockfd, SOMAXCONN);
    clilen = sizeof(cli_addr);

    timeval timeout;
    timeout.tv_sec = 15;
    timeout.tv_usec = 0;

    while (true) {

        cliSock = accept(sockfd, (struct sockaddr *) &cli_addr,
                         (socklen_t *) &clilen);
        info->sockfd = cliSock;
        if (cliSock < 0) {

            if (errno == EAGAIN || errno == EWOULDBLOCK) {
                stop();
                break;
            }
            perror("ERROR on accept");
            exit(1);
        }

        if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout,
                       sizeof(timeout)) == -1) {
            perror("ERROR on setting timeout");
        }

        pthread_t pthread;
        if (pthread_create(&pthread, nullptr,
                           MyParallelServer::parallelService,
                           info) != 0) {
            perror("thread failed");
        }
        this->threads.push_back(pthread);
    }
}


void *MyParallelServer::parallelService(void *newParams) {
    struct params *info = (struct params *) newParams;
    int sockfd = info->sockfd;
    info->clientHandler->handleClient(sockfd);
}

/*
 * making all the clients wait till all are done
 */
void MyParallelServer::stop() {
    for (auto thread: this->threads) {
        pthread_join(thread, nullptr);
    }
}