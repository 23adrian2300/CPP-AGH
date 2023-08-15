#include "shapecomposite.h"

#include <utility>

Shapes::ShapeComposite::ShapeComposite(std::shared_ptr<Shape> shape1, std::shared_ptr<Shape> shape2,
                                       Shapes::ShapeOperation operation) {
    shape1_ = std::move(shape1);
    shape2_ = std::move(shape2);
    operations_ = operation;
}

bool Shapes::ShapeComposite::isIn(int x, int y) const {
    if (operations_ == SUM){
        return shape1_->isIn(x,y) || shape2_->isIn(x,y);
    }
    else if (operations_ == INTERSECTION){
        return shape1_->isIn(x,y) && shape2_->isIn(x,y);
    }
    else if(operations_ == DIFFERENCE){
        return shape1_->isIn(x,y) && !shape2_->isIn(x,y);
    }
    else{
        return true;
    }
}
