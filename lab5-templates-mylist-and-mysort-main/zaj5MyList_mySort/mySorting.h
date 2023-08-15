#ifndef MYSORTING_H
#define MYSORTING_H

#include "myList.h"
#include <algorithm>
#include <cstring>
#include <vector>

template <class T, size_t size> void mySort(T(&sort)[size]){
    std::sort(sort, sort + size);
}

template <size_t size, size_t size2> void mySort(char(&sort)[size][size2])
{   size_t i;
    std::vector<std::string> vector(size);
    for (i = 0; i < size; ++i)
        vector[i] = std::string(sort[i]);
    std::sort(vector.begin(), vector.end(),
              [](const auto& item1, const auto& item2) {
                  return lexicographical_compare(item1.begin(), item1.end(), item2.begin(), item2.end(),
                                                 [](const char& c1, const char& c2) {
                                                     return toupper(c1) < toupper(c2);
                                                 });
              });
    for (i = 0; i < size; ++i)
        strcpy(sort[i], vector[i].c_str());
}

template <class T> void mySort(T& sort)
{
    std::sort(sort.begin(), sort.end());
}

template <class T> void mySort(MyList<T>& sort)
{
    std::vector<std::unique_ptr<class MyList<T>::Node>> vector(sort.size());
    vector[0] = std::move(sort.head_);
    size_t i;
    for (i=1; i < sort.size(); ++i)
        vector[i] = std::move(vector[i - 1]->next_);
    std::sort(vector.begin(), vector.end(),
              [](const auto& l, const auto& r) {
                  return l->value() < r->value();
              });
    for (i = sort.size() - 1; i > 0; --i)
        vector[i - 1]->next_ = std::move(vector[i]);
    sort.head_ = std::move(vector[0]);
}

#endif // MYSORTING_H