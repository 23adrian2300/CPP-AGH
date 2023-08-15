//
// Created by adria on 04.05.2023.
//

#include "circle.h"

Shapes::Circle::Circle(int xCenter, int yCenter, int radius){
    xCenter_ = xCenter;
    yCenter_ = yCenter;
    radius_ = radius;
}

bool Shapes::Circle::isIn(int x, int y) const {
    if ((x-xCenter_)*(x-xCenter_) + (y- yCenter_) * (y-yCenter_)<= radius_*radius_){
        return true;
    }
    else{
        return false;
    }
}

int Shapes::Circle::x() const {
    return xCenter_;
}

int Shapes::Circle::y() const {
    return yCenter_;
}

int Shapes::Circle::getRadius() const {
    return radius_;
}
