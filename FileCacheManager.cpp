//
// Created by efrat on 05/01/19.
//
#include <vector>
#include "FileCachManager.h"


bool FileCacheManager::haveSolution(string problem) {
    return this->solutionsMap.find(problem) != this->solutionsMap.end();
}


string FileCacheManager::getSolution(string problem){
    return this->solutionsMap.find(problem)->second;
}


void FileCacheManager::loadFile() {
    string line;
    string solution;
    string problem;
    FileCacheM.open("solutions.txt", ifstream::in | istream::app);
    if(!FileCacheM){
        throw "File Faild";
    }
    while(getline(FileCacheM,line)){
        string buff{""};
        vector<string> v;
        for(auto n:line) {
            if(n != '$') {
                buff += n;
            }
            else {
                v.push_back(buff);
                buff="";
            }
        }
        v.push_back(buff);
        problem=v[0];
        solution=v[1];
        this->solutionsMap.insert(pair<string,string>(problem,solution));
    }
    FileCacheM.close();
}


void FileCacheManager::addSolution(string problem, string solution) {
    FileCacheM.open ("solutions.txt", ofstream::out | ostream::app);
    if(!FileCacheM){
        throw "failed opening file";
    }
    FileCacheM << problem << "$" <<solution << endl;
    FileCacheM.close();
    //this->solutionsMap.insert(pair<string,string>(problem,solution));
}


void FileCacheManager::updateSolutions(string prob, string solution) {

    this->solutionsMap.insert(pair<string, string>(prob, solution));
}

