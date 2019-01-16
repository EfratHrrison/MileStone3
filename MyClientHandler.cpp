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
#include <mutex>
#include <sys/socket.h>

void MyClientHandler::handleClient(int clientSock) {
    string problem = "";
    string solution = "";
    char *whriteBack;
    int clilen;
    int x;
    int y;
    int n;
    int countLines = 0;
    vector<string> vector1;
    vector<string> vector2;
    vector<State<Point> *> MatrixV;
    char buffer[1024];

    if (clientSock < 0) {
        perror("ERROR on accept");
        exit(1);
    }


    while (true) {
        problem = "";
        MatrixV.clear();
        vector1.clear();
        vector2.clear();
        solution = "";

        string buff = "";

        vector<string> vectorBuff;
        // If connection is established then start communicating
        while (true) {
            //bzero(buffer, 256);
            char buffer[1024];
            int numBytesRead = recv(clientSock, buffer, sizeof(buffer), 0);
            if (numBytesRead > 0) {
                for (int i = 0; i < numBytesRead; ++i) {
                    char c = buffer[i];
                    if (c == '\n') {
                        if (buff.length() > 0) {
                            printf("Next command is [%s]\n", buff.c_str());
                            if (buff == "end") {
                                break;
                            }
                            vectorBuff.push_back(buff);
                            problem += buff;
                            problem += ".";
                            buff = "";
                        }
                    } else {
                        buff += c;
                    }
                }
            } else {
                printf("Socket closed or socket error!\n");
                break;
            }
            if (buff == "end") {
                buff = "";
                break;
            }
        }
//
//                bzero(buffer, 1000);
//            n = read(clientSock, buffer, 1000);
//            if (n < 0) {
//                perror("ERROR reading from socket");
//                exit(1);
//            }
//            //if the client entered "end" that means we are done
//            if(strcmp(buffer,"end")==0){
//                break;
//            }
//            vectorBuff.push_back(buffer);
//            problem+=buffer;
//            problem+=".";
//        }
            countLines = vectorBuff.size() - 2;
            //initiail point
            string s = vectorBuff[countLines];
            vector1 = explode(s, ',');
            x = std::stoi(vector1[0]);
            y = std::stoi(vector1[1]);
            Point initialP(x, y);

            //goal point
            s = vectorBuff[countLines + 1];
            vector1 = explode(s, ',');
            x = std::stoi(vector1[0]);
            y = std::stoi(vector1[1]);
            Point goalP(x, y);

            int row = countLines;
            string numOfClo = vectorBuff[0];
            vector2 = explode(numOfClo, ',');
            int col = vector2.size();
            for (int i = 0; i < row; i++) {
                s = vectorBuff[i];
                vector1 = explode(s, ',');
                for (int j = 0; j < col; j++) {
                    //put each point in a state point vector to create a searchebla
                    State<Point> *state = new State<Point>(Point(i, j), stod(vector1[j]));
                    MatrixV.push_back(state);
                }
            }
            Searchable<Point> *searchableM = new Matrix(MatrixV, this->getStatePoint(MatrixV, initialP),
                                                        this->getStatePoint(MatrixV, goalP));

            //if we dond have the problem already
            //solve the [roblem and save it in our cach manager
            if (!this->cacheManager->haveSolution(problem)) {
                solution = this->solver->solve(searchableM);
                this->cacheManager->updateSolutions(problem, solution);
                this->cacheManager->addSolution(problem, solution);
            }
                //we already have the solution for this problem
            else {
                solution = this->cacheManager->getSolution(problem);
            }
            whriteBack = const_cast<char *>(solution.c_str());
            //printf("Here is the message after: %s\n", whriteBack);
            n = write(clientSock, whriteBack, strlen(whriteBack));
            if (n < 0) {
                perror("ERROR writing to socket");
                exit(1);
            }

            for (State<Point> *state : searchableM->getSearchable()) {
                delete (state);
            }
            delete (searchableM);
            break;
        }
}
/**
 * this func retuns a spacific state point we need
 * @param searchable - all our atate points
 * @param initial the point we are looking for
 * @return the state point
 */
    State<Point> *MyClientHandler::getStatePoint(vector<State<Point> *> searchable, Point initial) {
        for (int i = 0; i < searchable.size(); ++i) {
            Point point(searchable[i]->getState().getX(), searchable[i]->getState().getY());
            if (point == initial) {
                return searchable[i];
            }
        }
    }
/**
 * this function split each line by a spacific char
 * @param s our string - line
 * @param c the char we are spliting according to him
 * @return vector of strings after we splited the string
 */
    vector<string> MyClientHandler::explode(string &s, const char &c) {
        string buff{""};
        vector<string> v;
        for (auto n:s) {
            if (n != c) {
                buff += n;
            } else {
                v.push_back(buff);
                buff = "";
            }
        }
        v.push_back(buff);
        return v;
    }
