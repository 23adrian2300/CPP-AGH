#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
/*
Proszę zaimplementować klasę `Circle` dziedziczącą po `Shape` i implementującą jej metodę.
    1. Implementacja klasy powinna być dokonana w nowo-utworzonych plikach: `circle.h` i `circle.cpp`
    2. Konstruktor powinien przyjmować wspolrzedne srodka, oraz promien `(int xCenter, int yCenter, int radius)`
*/

namespace Shapes {
    class Circle : public Shape{
    private:
        int xCenter_;
        int yCenter_;
        int radius_;
    public:
        Circle(int xCenter, int yCenter, int radius);
        [[nodiscard]] bool isIn(int x, int y) const override;
        [[nodiscard]] int x() const;
        [[nodiscard]] int y() const;
        [[nodiscard]] int getRadius() const;

    };
}

#endif //CIRCLE_H
