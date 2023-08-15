#include "mystring.h"

#include <utility>

//Konstruktory
MyString::MyString() {
    stext = std::string();
    ssize = stext.size();
    scapacity = initialBufferSize_ + stext.capacity();
    stext.reserve(initialBufferSize_);
}

MyString::MyString(const char *text) {
    stext = text;
    ssize = stext.size();
    scapacity = initialBufferSize_ + stext.capacity();
    stext.reserve(initialBufferSize_);
}

MyString::MyString(const std::string &text) {
    stext = text;
    ssize = text.length();
    scapacity = stext.capacity();
}

//początki
std::string::const_iterator MyString::begin() const {
    return stext.begin();
}

std::string::iterator MyString::begin() {
    return stext.begin();
}

std::string::const_iterator MyString::cbegin() const {
    return stext.cbegin();
}
// końce
std::string::iterator MyString::end() {
    return stext.end();
}

std::string::const_iterator MyString::cend() const {
    return stext.cend();
}

std::string::const_iterator MyString::end() const {
    return stext.end();
}

//pojemnosc
size_t MyString::capacity() const {
    return scapacity;
}

// wielkosc
size_t MyString::size() const {
    return ssize;
}

// czy puste
bool MyString::empty() const {
    return ssize == 0;
}

// przeciążenia
MyString &MyString::operator+=(const char character) {
    stext += character;
    ssize = stext.size();
    scapacity = stext.capacity();
    return *this;
}

std::ostream &operator<<(std::ostream &s, const MyString &mystring) {
    return s << mystring.stext;
}

std::istream &operator>>(std::istream &s, MyString &mystring) {
    std::string buffer;
    while (s >> buffer) {
        mystring.stext.append(buffer);
        mystring.stext.append(" ");
    }
    mystring.scapacity = mystring.stext.capacity();
    mystring.ssize = mystring.stext.size();
    return s;
}

bool MyString::operator!=(const MyString &mystring) const {
    std::pair sol = std::mismatch(stext.begin(), stext.end(), stext.begin());
    if (sol.first == stext.begin() && stext[0] == mystring[0]) {
        return false;
    }
    return true;
}

char MyString::operator[](size_t idx) const {
    if (idx >= ssize)
        throw std::out_of_range("Fail");
    return stext[idx];
}

bool MyString::operator<(const MyString &mystring) const {
    return stext.compare(mystring.stext) < 0;
}

bool MyString::operator==(const MyString &mystring) const {
    return stext == mystring.stext;
}

// wszystkie z...
bool MyString::all_of(std::function<bool(char)> predicate) const {
    return std::all_of(stext.begin(), stext.end(), std::move(predicate));
}

// dolacz
MyString MyString::join(const std::vector<MyString> &texts) const {
    MyString mystring;
    for (auto &&element: texts) {
        for (char c: element.stext)
            mystring += c;
        for (char sep: stext)
            mystring += sep;
    }
    for (int i = 0; i < stext.size(); i++)
        mystring.stext.pop_back();
    return mystring;
}

//generatory
MyString MyString::generateRandomWord(size_t size) {
    std::string word(size, ' ');
    std::generate_n(word.begin(), size, generateRandomChar);
    return MyString(word);
}

char MyString::generateRandomChar() {
    return rand() % 26 + 65 + rand() % 2 * 32;
}

//unikalne
std::set<MyString> MyString::getUniqueWords() const {
    std::set<MyString> uniq;
    std::string string_copy = stext;
    auto lower = [](char c) { return std::tolower(c); };
    auto isSpace = [](char c) { return std::isspace(c); };
    std::transform(string_copy.begin(), string_copy.end(), string_copy.begin(), lower);
    auto p = string_copy.begin();
    auto o = string_copy.begin();
    while (p != string_copy.end()) {
        p = std::find_if_not(p, string_copy.end(), isSpace);
        o = std::find_if(p, string_copy.end(), isSpace);
        auto pos = p - string_copy.begin();
        auto i = o - string_copy.begin();
        std::string word = string_copy.substr(pos, i - pos);
        uniq.insert(MyString(word));
        p = o;
    }
    return uniq;
}

//uzycia
std::map<MyString, size_t> MyString::countWordsUsageIgnoringCases() const {
    std::map<MyString, size_t> usage;
    auto isSpace = [](char c) { return std::isspace(c); };
    auto p = stext.begin();
    auto o = stext.begin();
    while (p != stext.end()) {
        p = std::find_if_not(p, stext.end(), isSpace);
        o = std::find_if(p, stext.end(), isSpace);
        auto pos = p - stext.begin();
        auto i = o - stext.begin();
        std::string str = stext.substr(pos, i - pos);
        std::transform(str.begin(), str.end(), str.begin(),
                       [](unsigned char c) { return std::tolower(c); });
        str.erase(std::remove_if(str.begin(), str.end(), [](char c) { return !std::isalpha(c); }), str.end());
        MyString myString(str);
        if (usage.find(myString) == usage.end())
            usage.insert(std::pair<MyString, size_t>(myString, 1));
        else
            usage.find(myString)->second++;
        p = o;
    }
    return usage;
}

// zaczynajace i konczące
bool MyString::startsWith(std::string str) const {
    auto search = std::search(stext.begin(), stext.end(), str.begin(), str.end());
    return search == stext.begin();
}

bool MyString::endsWith(std::string str) const {
    auto search = std::search(stext.begin(), stext.end(), str.begin(), str.end());
    return search == stext.end() - str.size();
}


// operacje
MyString &MyString::trim() {
    auto l = std::find_if_not(stext.begin(), stext.end(),
                              [](unsigned char c) { return std::isspace(c); });
    auto r = std::find_if_not(stext.rbegin(), stext.rend(),
                              [](unsigned char c) { return std::isspace(c); }).base();
    stext = std::string(l, r);
    ssize = stext.size();
    scapacity = stext.capacity();
}

MyString &MyString::toLower() {
    auto lower = [](char c) { return std::tolower(c); };
    std::transform(stext.begin(), stext.end(), stext.begin(), lower);
}

void MyString::clear() {
    stext.clear();
    ssize = 0;
    scapacity = 0;
}

