//
// Created by efrat on 05/01/19.
//
#include "MyTestClientHandler.h"
#include <unistd.h>
#include <strings.h>
#include <cstring>
void MyTestClientHandler::handleClient(int clientSock) {
    cout << "hi";
    string problem="";
    string solution="";
    int clilen;
    char* chr;

    //efrat harrison
    ssize_t n;
    while(true) {
        char buffer[1000];
        // If connection is established then start communicating
        bzero(buffer, 1000);
        n = read(clientSock, buffer, 1000);
        cout << n;

        //finish the conversetion.
        if(buffer=="end") {
            return;
        }
        printf("the message: %s\n", buffer);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        if(!this->cacheManager->haveSolution(buffer)){
            solution = this->solver->solve(buffer);
            this->cacheManager->updateSolutions(buffer,solution);
            this->cacheManager->addSolution(buffer,solution);
        }else{
            solution = this->cacheManager->getSolution(buffer);
        }
        chr = const_cast<char *>(solution.c_str());
        n = write(clientSock, chr, strlen(chr));
        cout<<solution<<endl;
        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }
    }
}
