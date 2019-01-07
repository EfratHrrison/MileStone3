//
// Created by efrat on 05/01/19.
//

#ifndef MILESTONE2_CACHEMANAGER_H
#define MILESTONE2_CACHEMANAGER_H
using namespace std;
#include <string>
#include <map>

template <class P,class S>
class CacheManager {
protected:
    map<string,string> solutionsMap;
public:
    virtual S getSolution(P problem)=0;
    virtual bool haveSolution(P problem)=0;
    virtual void addSolution(P problem, S solution)=0;
};

#endif //MILESTONE2_CACHEMANAGER_H
