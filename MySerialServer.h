//
// Created by efrat on 05/01/19.
//

#ifndef MILESTONE2_MYSERIALSERVER_H
#define MILESTONE2_MYSERIALSERVER_H

#include "Server.h"

class MySerialServer : public Server {
    int timeOut;
    int sockfd;
public:
    MySerialServer(){
        //this->timeOut=timeOut;
    }
    virtual void open(int port, ClientHandler *handler);
    virtual void stop();
    static void listenTo(int sockfd, ClientHandler *handler);
};

#endif //MILESTONE2_MYSERIALSERVER_H
