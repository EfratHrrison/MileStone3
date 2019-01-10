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


class FileCacheManager:public CacheManager {
fstream FileCacheM;
public:
    FileCacheManager(){
        loadFile();
    }
    void loadFile();
    virtual string getSolution(string problem);
    virtual bool haveSolution(string problem);
    virtual void addSolution(string problem, string solution);
    virtual void updateSolutions(string prob, string solution);
};

#endif //MILESTONE2_FILECACHMANAGER_H
