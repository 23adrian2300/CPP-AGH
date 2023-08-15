#ifndef MYSTRING_H
#define MYSTRING_H

#include <cstdlib>
#include <string>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>


class MyString {
private:
    std::string stext;
    size_t ssize;
    size_t scapacity;

public:
    // wielkość
    static const int initialBufferSize_ = 20;

    //Konstruktory
    MyString();

    MyString(const char *text);

    explicit MyString(const std::string &text);

    //początki
    [[nodiscard]] std::string::const_iterator begin() const;

    std::string::iterator begin();

    [[nodiscard]] std::string::const_iterator cbegin() const;

    //końce
    [[nodiscard]] std::string::const_iterator end() const;

    [[nodiscard]] std::string::const_iterator cend() const;

    std::string::iterator end();

    // rozmiar
    [[nodiscard]] size_t size() const;

    //pojemność
    [[nodiscard]] size_t capacity() const;

    //czy puste
    [[nodiscard]] bool empty() const;

    //przeciążenia
    bool operator!=(const MyString &mystring) const;

    bool operator<(const MyString &mystring) const;

    MyString &operator+=(char);

    bool operator==(const MyString &mystring) const;

    char operator[](size_t) const;

    friend std::ostream &operator<<(std::ostream &s, const MyString &mystring);

    friend std::istream &operator>>(std::istream &s, MyString &mystring);

    // wszytskie z...
    bool all_of(std::function<bool(char)> predicate) const;

    // dołącz
    [[nodiscard]] MyString join(const std::vector<MyString> &texts) const ;

    // generatory
    static char generateRandomChar();

    static MyString generateRandomWord(size_t len);

    //unikalne
    [[nodiscard]] std::set<MyString> getUniqueWords() const;

    // użycia
    [[nodiscard]] std::map<MyString, size_t> countWordsUsageIgnoringCases() const;

    // zaczynajace i konczące
    [[nodiscard]] bool startsWith(std::string str) const;

    [[nodiscard]] bool endsWith(std::string str) const;

    //operacje na stringu
    MyString &toLower();

    MyString &trim();

    void clear();
};


#endif //MYSTRING_H
