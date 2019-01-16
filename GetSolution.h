//
// Created by efrat on 10/01/19.
//

#ifndef MILESTONE3_GETSOLUTION_H
#define MILESTONE3_GETSOLUTION_H
#include "Solver.h"
#include "Searcher.h"
#include "Point.h"

class GetSolution : public Solver<Searchable<Point>*, string> {
    Searcher<Point>* searcher;
public:
    GetSolution(Searcher<Point>* searcher1) {
        this->searcher = searcher1;
    }

    virtual string solve(Searchable<Point>* p) {
        return this->searcher->search(p);
    }

    virtual ~GetSolution() {
        delete (searcher);
    }
};
#endif //MILESTONE3_GETSOLUTION_H
