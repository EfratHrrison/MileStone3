#include <sys/socket.h>
#include <netinet/in.h>
#include <cstdlib>
#include <strings.h>
#include <cstdio>
#include <thread>
#include <iostream>
#include "MyParallelServer.h"

void MyParallelServer::open(int port, ClientHandler *c) {
    int sockfd, portno;

    struct sockaddr_in serv_addr;

    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

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
    int newsockfd, clilen;
    struct sockaddr_in cli_addr;
    struct params* info = new params;
    listen(sockfd, SOMAXCONN);
    clilen = sizeof(cli_addr);
    timeval timeout;
    timeout.tv_sec = 1000;
    timeout.tv_usec = 0;

    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));


    while (true) {
        /* Accept actual connection from the client */
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);
        cout<<"sockfd: "<< newsockfd<<endl;

        if (newsockfd < 0)	{
            if (errno == EWOULDBLOCK)	{
                stop();
            }	else	{
                perror("other error");
                exit(3);
            }
        }
        //setting params
        info->sockfd = newsockfd;
        info->clientHandler = c;
        pthread_t thread;
        //creating thread and sending to handle client
        if (pthread_create(&thread, nullptr, MyParallelServer::parallelService,info) != 0){
            perror("thread failed");
        }
        threads.push_back(thread);

    }
}

void* MyParallelServer::parallelService(void* newParams) {
    struct params *info = (struct params*)newParams;
    int sockfd = info->sockfd;
    info->clientHandler->handleClient(sockfd);
}

/*
 * making all the clients wait till all are done
 */
void MyParallelServer::stop() {
    for (auto thread: this->threads) {
        pthread_join(thread, NULL);
    }
}