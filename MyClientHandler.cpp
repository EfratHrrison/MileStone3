//
// Created by efrat on 05/01/19.
//
#include "MyClientHandler.h"
#include <unistd.h>
#include <strings.h>
#include "iostream"
#include <cstring>
#include <vector>
#include "Point.h"
#include "string"
#include "State.h"
#include "Matrix.h"
void MyClientHandler::handleClient(int clientSock) {
    string problem="";
    string solution="";
    int clilen;
    char* chr;
    int x; int y;
    int countMat;
    int rowMat;
    bool flag=false;
    Point* initialP;
    Point* goalP;
    vector<string> vector1;
    vector<State<Point>*> MatrixV;
    //State<Point>* state;
    Matrix *matrix;


    ssize_t n;
    while(true) {
        char buffer[1000];
        // If connection is established then start communicating
        bzero(buffer, 1000);
        n = read(clientSock, buffer, 1000);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
        //finish the conversetion.
        if(buffer=="end") {
            return;
        }
         countMat=atoi(buffer);

         for(int p=0 ; p<countMat;p++){
             for(int i=0 ; i< 3 ; i++) {

                 n = read(clientSock, buffer, 1000);
                 if (n < 0) {
                     perror("ERROR reading from socket");
                     exit(1);
                 }
                 if(!i) {
                     rowMat=atoi(buffer);
                 }
                 if (i) {
                     string s = buffer;
                     vector1= explode(s,',');
                     x = std::stoi(vector1[0]);
                     y = std::stoi(vector1[1]);
                     initialP = new Point(x,y);
                 }
                 else {
                     string s = buffer;
                     vector1= explode(s,',');
                     x = std::stoi(vector1[0]);
                     y = std::stoi(vector1[1]);
                     goalP = new Point(x,y);
                 }
             }
             for(int i=0 ; i< rowMat ; i++) {
                 n = read(clientSock, buffer, 1000);
                 string s = buffer;
                 vector1= explode(s,',');
                 for(int j=0 ; j< rowMat; j++) {
                     State<Point>*  state = new State<Point>(new Point(i,j),std::stoi(vector1[j]));
                     MatrixV.push_back(state);
                 }
             }
             matrix=new Matrix(MatrixV);
             if(!this->cacheManager->haveSolution(matrix)){
                 solution = this->solver->solve(matrix);
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
    return v;
}
