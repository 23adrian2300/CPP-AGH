#include <iostream>
#include <string>
#include <stdexcept> // std::out_of_range()
#include <iomanip>   // std::setw()


#include "matrix.h"

#ifndef _MSC_FULL_VER // if not Visual Studio Compiler
#warning "Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym"
#else
#pragma message ("Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym")
#endif
//konstruktor bezparametrowy
TwoDimensionMatrix::TwoDimensionMatrix() {
    size_t i, j;
    for (i = 0; i < size_; ++i)
        for (j = 0; j < size_; ++j)
            matrix_[i][j] = 0;

}
//konstruktor
TwoDimensionMatrix::TwoDimensionMatrix(const TwoDimensionMatrix &firstmatrix) {
    size_t i, j;
    for (i = 0; i < size_; ++i)
        for (j = 0; j < size_; ++j)
            matrix_[i][j] = firstmatrix.get(i, j);
}
//konstruktor
TwoDimensionMatrix::TwoDimensionMatrix(const MatrixElement firstmatrix[size_][size_]) {
    for (size_t row = 0; row < size_; ++row)
        for (size_t col = 0; col < size_; ++col)
            matrix_[row][col] = firstmatrix[row][col];
}

//getter
MatrixElement TwoDimensionMatrix::get(size_t row, size_t col) const {
    return matrix_[row][col];
}
//przeciążenie =
TwoDimensionMatrix &TwoDimensionMatrix::operator=(const TwoDimensionMatrix &firstmatrix) {
    size_t i, j;
    for (i = 0; i < size_; ++i)
        for (j = 0; j < size_; ++j)
            matrix_[i][j] = firstmatrix.get(i, j);
    return (*this);
}
//przeciążenie >>
std::istream &operator>>(std::istream &is, TwoDimensionMatrix &firstmatrix) {
    for (size_t i = 0; i < TwoDimensionMatrix::size(); i++) {
        for (size_t j = 0; j < TwoDimensionMatrix::size(); j++) {
            is >> firstmatrix.matrix_[i][j];
        }
    }
    return is;
}
//przeciążenie <<
std::ostream &operator<<(std::ostream &os, const TwoDimensionMatrix &firstmatrix) {
    size_t i,j;
    for (i = 0; i < TwoDimensionMatrix::size(); i++) {
        for (j = 0; j < TwoDimensionMatrix::size(); j++) {
            os << firstmatrix.get(i, j);
            os <<" ";
        }
        os << std::endl;
    }
    return os;
}
//przeciążenie *=
TwoDimensionMatrix &TwoDimensionMatrix::operator*=(MatrixElement number) {
    size_t i,j;
    for (i=0;i<size_;i++)
        for (j=0;j<size_;j++)
            matrix_[i][j]*=number;

    return (*this);
}
//przeciążenie +
TwoDimensionMatrix operator+(const TwoDimensionMatrix &matrix1, const TwoDimensionMatrix &matrix2) {
    TwoDimensionMatrix result;
    size_t i,j;
    for (i=0;i<TwoDimensionMatrix::size();i++) {
        for (j = 0; j < TwoDimensionMatrix::size(); j++){
            //mozna by tez odwolac sie za pomoca matrix1[i][j]
            result[i][j] = matrix1.get(i, j) + matrix2.get(i, j);}
    }
    return result;
}
//przeciążenie &&
TwoDimensionMatrix TwoDimensionMatrix::operator&&(const TwoDimensionMatrix &matrix) const {
    TwoDimensionMatrix result;
    size_t i,j;
    for (i=0;i<TwoDimensionMatrix::size();i++) {
        for (j = 0; j < TwoDimensionMatrix::size(); j++){
            result[i][j] = matrix_[i][j] && matrix.get(i, j);}
    }
    return result;
}



