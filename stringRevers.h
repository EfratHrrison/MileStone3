//
// Created by efrat on 07/01/19.
//

#ifndef MILESTONE2_STRINGREVERS_H
#define MILESTONE2_STRINGREVERS_H

#include "Solver.h"

#include <string>

using namespace std;

//template <class s, class b>
class stringRevers: public Solver<string,string> {

public:
    virtual string solve(string problem);
};

#endif //MILESTONE2_STRINGREVERS_H
