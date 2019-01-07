//
// Created by efrat on 05/01/19.
//

#ifndef MILESTONE2_FILECACHMANAGER_H
#define MILESTONE2_FILECACHMANAGER_H

#include <fstream>
#include <iostream>
#include "CacheManager.h"
#include <map>
#include <string>

template <class P, class S>
class FileCacheManager:public CacheManager<P,S> {
fstream FileCacheM;
public:
    FileCacheManager(){
        loadFile();
    }
    void loadFile();
    virtual S getSolution(P problem);
    virtual bool haveSolution(P problem);
    virtual void addSolution(P problem, S solution);
    virtual void updateSolutions(P prob, S solution);
};

#endif //MILESTONE2_FILECACHMANAGER_H
