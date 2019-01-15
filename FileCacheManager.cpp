//
// Created by efrat on 05/01/19.
//
#include <vector>
#include "FileCachManager.h"

/**
 * this function checks if we already have the problem
 * in our file
 * @param problem - the problem we are looking for
 * @return true if we have it, false otherwise
 */
bool FileCacheManager::haveSolution(string problem) {
    pthread_mutex_lock(&mutex);
    if(this->solutionsMap.find(problem) != this->solutionsMap.end()){
        pthread_mutex_unlock(&mutex);
        return true;
    }else{
        pthread_mutex_unlock(&mutex);
        return false;
    }
}
/**
 * this function returns the solution from the file
 * @param problem
 * @return the solution
 */
string FileCacheManager::getSolution(string problem){
    pthread_mutex_lock(&mutex);
    string solution= this->solutionsMap.find(problem)->second;
    pthread_mutex_unlock(&mutex);
    return solution;
}


void FileCacheManager::loadFile() {
    string line;
    string solution;
    string problem;
    FileCacheM.open("pro&sol.txt", ifstream::in | istream::app);
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
        pthread_mutex_lock(&mutex);
        this->solutionsMap.insert(pair<string,string>(problem,solution));
        pthread_mutex_unlock(&mutex);
        solution="";
        problem="";
    }
    FileCacheM.close();
}


void FileCacheManager::addSolution(string problem, string solution) {
    FileCacheM.open ("pro&sol.txt", ofstream::out | ostream::app);
    if(!FileCacheM){
        throw "failed opening file";
    }
    FileCacheM << problem << "$" <<solution << + "\n";
    FileCacheM.close();
}


void FileCacheManager::updateSolutions(string prob, string solution) {
    pthread_mutex_lock(&mutex);
    this->solutionsMap.insert(pair<string, string>(prob, solution));
    pthread_mutex_unlock(&mutex);
}

