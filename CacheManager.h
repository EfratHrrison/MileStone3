//
// Created by efrat on 05/01/19.
//

#ifndef MILESTONE2_CACHEMANAGER_H
#define MILESTONE2_CACHEMANAGER_H
using namespace std;
#include <string>
#include <map>


class CacheManager {
protected:
    map<string,string> solutionsMap;
    mutable pthread_mutex_t mutex;
public:
    virtual string getSolution(string problem)=0;
    virtual bool haveSolution(string problem)=0;
    virtual void addSolution(string problem, string solution)=0;
    virtual void updateSolutions(string prob, string solution) = 0;
    ~CacheManager(){
        pthread_mutex_destroy(&mutex);
    }
};

#endif //MILESTONE2_CACHEMANAGER_H
