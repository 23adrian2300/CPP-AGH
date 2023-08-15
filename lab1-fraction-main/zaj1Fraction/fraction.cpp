#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

#include "fraction.h"

#ifdef UNIMPLEMENTED_classFraction
#ifndef _MSC_FULL_VER // if not Visual Studio Compiler
    #warning "Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym"
#else
    #pragma message ("Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym")
#endif
#endif // UNIMPLEMENTED_classFraction

//Konstruktory
Fraction::Fraction() {
    numerator_ = 0;
    denominator_ = 1;
}

Fraction::Fraction(int numerator, int denominator) {
    if (denominator !=getInvalidDenominatorValue()) {
        numerator_ = numerator;
        denominator_ = denominator;
    }
    else{
        cout<<"Wrong value of denominator"<<endl;
    }
}

Fraction::Fraction(int numerator, int denominator, string fractionName) {
    numerator_ = numerator;
    denominator_ = denominator;
    fractionName_ = std::move(fractionName);
}

//Destruktor
Fraction::~Fraction() {
    increaseRemovedFractions();
}

/*
Zamiennie z inline przy definicji można zastosować:
int Fraction::removedFractions_ = 0;
*/

//gettery
int Fraction::getNumerator() const {
    return numerator_;
}

int Fraction::getDenominator() const {
    return denominator_;
}

string Fraction::getFractionName() const {
    return fractionName_;
}

int Fraction::getInvalidDenominatorValue() {
    return invalidDenominatorValue;
}

int Fraction::getDefaultDenominatorValue(){
    return defaultDenominatorValue;
}

//settery
void Fraction::setNumerator(int numerator) {
    numerator_ = numerator;
}

void Fraction::setDenominator(int denominator) {
    if (denominator != getInvalidDenominatorValue()) {
        denominator_ = denominator;
    }
}

//removedFractions()
int Fraction::removedFractions() {
    return removedFractions_;
}

//Funkcja potrzebna do zwiększania w destruktorze
void Fraction::increaseRemovedFractions() {
    removedFractions_ += 1;
}

//print
void Fraction::print() const {
    cout << numerator_ << "/" << denominator_ << endl;
}

//wczytywanie
void Fraction::load(istream &is) {
    char c;
    string denominator, numerator;
    bool flag = false;
    while (is.get(c)) {
        if (!flag) {
            numerator += c;
        }
        if (flag) {
            denominator += c;
        }
        if (c == '/') {
            flag = true;
        }

    }
    // zamiana ze stringów na inty
    denominator_ = stoi(denominator);
    numerator_ = stoi(numerator);
}

//save
void Fraction::save(std::ostream &os) const {
    os << numerator_ << "/" << denominator_;
}
