//
// Created by neta on 1/9/19.
//

#ifndef MILESTONE3_POINT_H
#define MILESTONE3_POINT_H


class Point {
    int x;
    int y;
public:
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    Point* getPoint() {
        return this;
    }

    int getX() {
        return this->x;
    }

    int getY() {
        return this->y;
    }

    bool operator==(Point* point) {
        return ((this->x == point->getX()) && (this->y == point->getY()));
    }

    void setPoint(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

#endif //MILESTONE3_POINT_H
