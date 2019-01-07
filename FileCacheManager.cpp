//
// Created by efrat on 05/01/19.
//
#include "FileCachManager.h"

template <class P,class S>
bool FileCacheManager<P,S>::haveSolution(P problem) {
    return this->solutionsMap.find(problem) != this->solutionsMap.end();
}

template <class P,class S>
S FileCacheManager<P,S>::getSolution(P problem){
    return this->solutionsMap.find(problem)->second;
}

template <class P,class S>
void FileCacheManager<P,S>::loadFile() {
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

template <class P,class S>
void FileCacheManager<P,S>::addSolution(P problem, S solution) {
    FileCacheM.open ("solutions.txt", ofstream::out | ostream::app);
    if(!FileCacheM){
        throw "failed opening file";
    }
    FileCacheM << problem << "$" <<solution << endl;
    FileCacheM.close();
    //this->solutionsMap.insert(pair<string,string>(problem,solution));
}

template <class P,class S>
void FileCacheManager<P,S>::updateSolutions(P prob, S solution) {

    this->solutionsMap.insert(pair<string, string>(prob, solution));
}

