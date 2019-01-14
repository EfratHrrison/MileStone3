#include "MyParallelServer.h"
#include <cstring>

void MyParallelServer::open(int port, ClientHandler *handler) {

    int sockfd, portno;
    struct sockaddr_in serv_addr;

    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    /*this->passingData->sockfd = sockfd;*/
    this->passingData->clientHandler=handler;
    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = port;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    cout<<"hi 3"<<endl;
    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }
    struct sockaddr_in cli_addr;
    int clilen, cliSock;
    listen(sockfd, SOMAXCONN);
    clilen = sizeof(cli_addr);

    timeval timeout;
    timeout.tv_sec = 10000;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout, sizeof(timeout));
    while(true){
        cliSock = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);
        this->passingData->sockfd = cliSock;
        if (cliSock < 0) {
            if (errno == EWOULDBLOCK) {
                cout << "Time Out!" << endl;
                stop();
            } else {
                perror("ERROR on accept");
                exit(1);
            }
        }
        pthread_t pthread;
        if(pthread_create(&pthread, nullptr,MyParallelServer::threadManager,passingData)!=0){
            perror("thread failed");
        }
        this->threads.push_back(pthread);
    }

}

void *MyParallelServer::threadManager(void *data) {
    struct dataPass *passingData = (struct dataPass *) data;
    passingData->clientHandler->handleClient(passingData->sockfd);

}

void MyParallelServer::stop() {
    for(int i=0;i<this->threads.size();++i){
        pthread_join(this->threads[i],NULL);
        //delete(this->threads[i]);
    }

}