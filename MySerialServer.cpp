//
// Created by efrat on 05/01/19.
//

#include "MySerialServer.h"
#include <vector>
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include <thread>
#include <netinet/in.h>
#include <unistd.h>
using namespace std;

void MySerialServer::open(int port, ClientHandler *handler) {
    int sockfd ,portno;
    struct sockaddr_in serv_addr;

    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
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

    /* Now start listening for the clients, here process will
       * go in sleep mode and will wait for the incoming connection
    */

    thread t(listenTo, sockfd,handler);
    t.detach();
}

void MySerialServer::listenTo(int sockfd, ClientHandler *handler) {
    int newsockfd, clilen;
    struct sockaddr_in cli_addr;

    while (true) {
        listen(sockfd, 5);
        clilen = sizeof(cli_addr);
        /* Accept actual connection from the client */
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);
        handler->handleClient(newsockfd);
    }
}

void MySerialServer::stop() {

}