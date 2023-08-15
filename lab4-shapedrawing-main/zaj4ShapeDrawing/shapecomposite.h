#ifndef SHAPECOMPOSITE_H
#define SHAPECOMPOSITE_H

#include <memory>
#include "shape.h"
/*
Proszę zaimplementować klasę-kompozyt `ShapeComposite` dziedziczącą po `Shape` i implementującą jej metodę.
Klasa ta w konstruktorze powinna przyjąć:
    1. dwie instancje `shared_ptr<Shape>`
    2. operacje na zbiorach `enum class ShapeOperation`: `INTERSECTION`, `SUM`, `DIFFERENCE`
    3. w oparciu o to bedzie mozna cala hierarchie figur polaczyc w jedno drzewo,
       dla ktorego bedzie mozna zapytac czy dany punkt jest w hierarchii, czy nie (metoda `isIn`).
 */

namespace Shapes {
    enum ShapeOperation{
        INTERSECTION,
        SUM,
        DIFFERENCE
    };

    class ShapeComposite : public Shape{
    private:
        std::shared_ptr<Shape> shape1_;
        std::shared_ptr<Shape> shape2_;
        enum ShapeOperation operations_;
    public:
        ShapeComposite(std::shared_ptr<Shape> shape1, std::shared_ptr<Shape> shape2,
                       Shapes::ShapeOperation operation);
        [[nodiscard]] bool isIn(int x, int y) const override;
    };
}

#endif //SHAPECOMPOSITE_H
