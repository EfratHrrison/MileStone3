//
// Created by efrat on 07/01/19.
//

#include <algorithm>
#include "stringRevers.h"

string stringRevers::solve(string problem) {
    reverse(problem.begin(),problem.end());
    return problem;
}