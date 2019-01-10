//
// Created by efrat on 05/01/19.
//
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
        if (size_t found = line.find("$") != string::npos)
        {
            problem = line.substr(0,found);
            solution = line.substr(found+1, string::npos);
        }
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

