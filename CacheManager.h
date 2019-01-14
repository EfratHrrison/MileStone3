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
public:
    virtual string getSolution(string problem)=0;
    virtual bool haveSolution(string problem)=0;
    virtual void addSolution(string problem, string solution)=0;
    virtual void updateSolutions(string prob, string solution) = 0;
    ~CacheManager(){
    }
};

#endif //MILESTONE2_CACHEMANAGER_H
