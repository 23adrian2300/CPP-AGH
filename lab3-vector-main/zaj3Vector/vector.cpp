// author: Grzegorz Prowadzacy

#include <algorithm>
#include <stdexcept>
#include <utility> // std::swap()
#include <cstring>
#include "vector.h"

#ifndef _MSC_FULL_VER // if not Visual Studio Compiler
    #warning "Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym"
#else
    #pragma message ("Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym")
#endif
// TODO: zaimplementowac metody klasy, usunac ten komentarz i warning powyzszy


Vector::Vector(std::size_t capacity) {
    data_ = new Fraction[capacity];
    size_ = 0;
    capacity_ = capacity;
}
// destruktor
Vector::~Vector() {
    if (data_ != nullptr) {
        delete[] data_;
        data_ = nullptr;
    }
    size_ = 0;
    capacity_ = 0;
    data_ = nullptr;
}

Vector::Vector(const Vector &vector) {
    size_t capacity = vector.capacity_;
    data_ = new Fraction[capacity];
    size_ = vector.size();
    capacity_ = capacity;
    std::copy(vector.data(), vector.data() + size_, data_);
}
Vector::Vector(Vector &&vector) noexcept{
    data_ = vector.data_;
    size_= vector.size();
    capacity_ = vector.capacity();
    vector.data_ = nullptr;
    vector.size_ = 0;
    vector.capacity_ = 0;
}

void Vector::push_back(const Fraction &fraction) noexcept {
    if (size_ == capacity_) {
        auto *newData = new Fraction[capacity_+1];
        std::copy(data_, data_ + size_, newData);
        delete[] data_;
        data_ = newData;
        capacity_++;
    }
    data_[size_] = fraction;
    size_++;
}


Vector &Vector::operator=(const Vector &vector) noexcept {
    if (this == &vector)
        return *this;
    delete[] data_;
    size_ = vector.size();
    capacity_ = vector.capacity();
    data_ = new Fraction[capacity_];
    std::copy(vector.data(), vector.data() + size_, data_);
    return *this;
}

Vector &Vector::operator=(Vector &&vector) noexcept {
    if (this != &vector) {
        delete[] data_;
        data_ = vector.data_;
        size_ = vector.size();
        capacity_ = vector.capacity();
        vector.data_ = nullptr;
        vector.size_ = 0;
        vector.capacity_ = 0;
    }
    return *this;
}


Fraction &Vector::operator[](size_t index) const {
    if (size_ <= index)
        throw std::out_of_range("Element out of range");
    return data_[index];
}

Fraction &Vector::operator[](size_t index) {
    if (size_ <= index)
        throw std::out_of_range("Element out of range");
    return data_[index];;
}