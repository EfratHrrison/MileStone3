//
// Created by efrat on 05/01/19.
//

#ifndef MILESTONE2_SOLVER_H
#define MILESTONE2_SOLVER_H

#include <string>
using namespace std;
template <class P,class S>
class Solver {

public:
    virtual S solve(P problem)=0;
    virtual ~Solver() = default;
};

#endif //MILESTONE2_SOLVER_H
