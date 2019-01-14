//
// Created by efrat on 05/01/19.
//
#include "MyClientHandler.h"
#include <unistd.h>
#include <strings.h>
#include "iostream"
#include <cstring>
#include "string"
#include "Matrix.h"

void MyClientHandler::handleClient(int clientSock) {
    string problem="";
    string solution="";
    char *whriteBack;
    int clilen;
    char* chr;
    int x; int y;
    int countMat;
    int countLines =0;
    int rowMat;
    bool flag=false;
    vector<string> vector1;
    vector<State<Point>*> MatrixV;
    Matrix *matrix;

    ssize_t n;
    while(true) {
        char buffer[1000];
        vector<string> vectorBuff;
        // If connection is established then start communicating
        while(true){
            bzero(buffer, 1000);
            n = read(clientSock, buffer, 1000);
            if (n < 0) {
                perror("ERROR reading from socket");
                exit(1);
            }
            if(strcmp(buffer,"end")==0){
                break;
            }
            vectorBuff.push_back(buffer);
            problem+=buffer;
            problem+=".";
        }
        countLines=vectorBuff.size()-2;
        //initiail point
        string s = vectorBuff[countLines];
        vector1= explode(s,',');
        x = std::stoi(vector1[0]);
        y = std::stoi(vector1[1]);
        Point initialP(x,y);

        //goal point
        s = vectorBuff[countLines+1];
        vector1= explode(s,',');
        x = std::stoi(vector1[0]);
        y = std::stoi(vector1[1]);
        Point goalP(x,y);

        int row=countLines;
        int col=vectorBuff[0].size()-2;
        for(int i=0 ; i< row ; i++) {
            s = vectorBuff[i];
            vector1= explode(s,',');
            for(int j=0 ; j< col; j++) {
                State<Point>* state = new State<Point>(Point(i, j), stod(vector1[j]));
                MatrixV.push_back(state);
            }
        }
        Searchable<Point>* searchableM = new Matrix(MatrixV,this->getStatePoint(MatrixV,initialP),this->getStatePoint(MatrixV,goalP));

        if(!this->cacheManager->haveSolution(problem)) {
            solution = this->solver->solve(searchableM);
            this->cacheManager->updateSolutions(problem,solution);
            this->cacheManager->addSolution(problem,solution);
        }
            //we already have the solution for this problem
        else{
            solution = this->cacheManager->getSolution(problem);
        }
        whriteBack = const_cast<char *>(solution.c_str());

        printf("Here is the message after: %s\n", whriteBack);

        n = write(clientSock, whriteBack, strlen(whriteBack));
        cout<<solution<<endl;
        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }
    }
}

State<Point>* MyClientHandler::getStatePoint(vector<State<Point> *> searchable, Point initial) {
    for (int i = 0; i < searchable.size(); ++i) {
        Point point(searchable[i]->getState().getX(), searchable[i]->getState().getY());
        if (point == initial) {
            return searchable[i];
        }
    }
}

vector<string> MyClientHandler::explode(string& s, const char& c) {
    string buff{""};
    vector<string> v;
    for(auto n:s) {
        if(n != c) {
            buff += n;
        }
        else {
            v.push_back(buff);
            buff="";
        }
    }
    v.push_back(buff);
    return v;
}
