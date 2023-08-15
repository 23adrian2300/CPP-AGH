#include <iostream>
#include <stdexcept> // std::out_of_range
#include <numeric>   // std::gcd

#include "fraction.h"

#ifndef _MSC_FULL_VER // if not Visual Studio Compiler
    #warning "Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym"
#else
    #pragma message ("Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym")
#endif
// TODO: zaimplementowac metody klasy, usunac ten komentarz i warning powyzszy



Fraction::Fraction(int numerator, int denominator) {
    numerator_ = numerator;
    if (denominator == 0){
        throw std::invalid_argument("Denominator!=0");
    }
    denominator_ = denominator;
}


void Fraction::setDenominator(int denominator) {
    if (denominator ==0){
        throw std::invalid_argument("Denominator!=0");
    }
    denominator_ = denominator;
}

void Fraction::setNumerator(int numerator) {
    numerator_ = numerator;
}

Fraction Fraction::reducingFraction(Fraction fraction) {
    int numerator = fraction.numerator();
    int denominator = fraction.denominator();
    int divisor = std::gcd(numerator,denominator);
    numerator = numerator/divisor;
    denominator = denominator/divisor;
    if (denominator ==0){
        throw std::invalid_argument("Denominator!=0");
    }
    return Fraction(numerator,denominator);
}


Fraction Fraction::operator+(const Fraction &other) const {
    int newNumerator = numerator_*other.denominator() + denominator_ * other.numerator();
    int newDenominator = denominator_ * other.denominator();
    if (newDenominator == 0){
        throw std::invalid_argument("Denominator != 0");
    }
    Fraction newFraction = reducingFraction(Fraction(newNumerator, newDenominator));
    return  newFraction;
}

Fraction Fraction::operator*(const Fraction &other) const {
    int newNumerator = numerator_* other.numerator();
    int newDenominator = denominator_ * other.denominator();
    if (newDenominator == 0){
        throw std::invalid_argument("Denominator!=0");
    }
    Fraction newFraction = reducingFraction(Fraction(newNumerator,newDenominator));
    return newFraction;
}


