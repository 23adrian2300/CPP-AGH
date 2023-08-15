#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"
/*
Proszę zaimplementować klasę `Rectangle` dziedziczącą po `Shape` i implementującą powyższą metodę.
    1. Implementacja klasy powinna być dokonana w nowo-utworzonych plikach: `rectangle.h` i `rectangle.cpp`
    2. Konstruktor powinien przyjmować położenia współrzędnych dwóch: dolnegolewego i gornegoprawego `(xFrom, yFrom, xTo, yTo)`
    3. Odpowiada to prostokątowi o bokach równoległych do osi wykresu
 */

namespace Shapes {
    class Rectangle : public Shape{
    private:
        int xFrom_;
        int yFrom_;
        int xTo_;
        int yTo_;
    public:
        Rectangle(int xFrom, int yFrom, int xTo, int yTo);
        [[nodiscard]] bool isIn(int x, int y) const override;
        [[nodiscard]] int x() const;
        [[nodiscard]] int y() const;
        [[nodiscard]] int xTo() const;
        [[nodiscard]] int yTo() const;
    };
}

#endif //RECTANGLE_H
