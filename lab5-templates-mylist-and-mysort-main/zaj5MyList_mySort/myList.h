#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>
#include <memory>
#include <stdexcept>
#include <algorithm>

#define IMPLEMENTED_constructorOfEmptyList
#define IMPLEMENTED_pushingAndPopingElementsFront
#define IMPLEMENTED_nodesStoredAsUniquePtrs
#define IMPLEMENTED_popFromWhenEmptyList
#define IMPLEMENTED_copyingDisabled
#define IMPLEMENTED_removingElements
#define IMPLEMENTED_iteratorOperations
#define IMPLEMENTED_iteratorWithRangedForLoop
#define IMPLEMENTED_iteratorWithStlAlgorithm
#define IMPLEMENTED_ostreamOperator

template<class T>
class MyList {
public:
    using value_type = T;
    class Node;
    class Iterator;
    class ConstIterator;

public:
    std::unique_ptr<Node> head_;
    MyList() = default;
    MyList(const MyList<T>&) = delete;
    T front() const;
    [[nodiscard]] size_t size() const {
        return size_;
    }
    MyList<T>& operator=(const MyList<T>&) = delete;
    void push_front(const T& t);
    T pop_front();
    void remove(const T& t);
    Iterator begin() {
        return Iterator(head_.get());
    }
    ConstIterator begin() const {
        return ConstIterator(head_.get());
    }
    Iterator end() {
        return Iterator();
    }
    ConstIterator end() const {
        return ConstIterator();
    }
private:
    size_t size_ = 0;
};

template<class T>
T MyList<T>::front() const {
    if (!head_)
        throw std::out_of_range("Empty");
    return head_->value();
}

template<class T>
void MyList<T>::push_front(const T& t) {
    std::unique_ptr<Node> node = std::make_unique<Node>(t);
    node->next_ = std::move(head_);
    head_ = std::move(node);
    size_+=1;
}

template<class T>
T MyList<T>::pop_front() {
    if (!head_)
        throw std::out_of_range("Empty");
    T value = head_->value();
    head_ = std::move(head_->next_);
    size_-=1;
    return value;
}

template<class T>
void MyList<T>::remove(const T& t) {
    std::unique_ptr<Node>* pUniquePtr = &head_;
    while (*pUniquePtr) {
        if ((*pUniquePtr)->value() == t) {
            *pUniquePtr = std::move((*pUniquePtr)->next_);
            size_-=1;
        } else {
            pUniquePtr = &((*pUniquePtr)->next_);
        }
    }
}

template<class T>
std::ostream& operator<<(std::ostream& ostream, const MyList<T>& list) {
    for (auto node : list)
        ostream << node << " -> ";
    ostream << "\n";
    return ostream;
}

template<class T>
class MyList<T>::Node {
public:
    std::unique_ptr<Node> next_ = nullptr;
    explicit Node(const T& value) : value_(value) {}
    T& value() {
        return value_;
    }
    const T& value() const {
        return value_;
    }
private:
    T value_;
};

template<class T>
class MyList<T>::Iterator {
private:
    Node* pNode;
public:
    using value_type = T;
    using reference = T&;
    using pointer = T*;
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;

    explicit Iterator() noexcept : pNode(nullptr) {}

    explicit Iterator(Node* node) noexcept : pNode(node) {}

    Iterator& operator++() noexcept {
        pNode = pNode->next_.get();
        return *this;
    }

    bool operator!=(const Iterator& other) const noexcept {
        return pNode != other.pNode;
    }

    reference operator*() noexcept {
        return pNode->value();
    }

    pointer operator->() noexcept {
        return &(pNode->value());
    }
};

template<class T>
class MyList<T>::ConstIterator {
private:
    const Node* pNode;
public:
    using value_type = T;
    using reference = const T&;
    using pointer = const T*;
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;

    explicit ConstIterator() noexcept : pNode(nullptr) {}
    explicit ConstIterator(const Node* node) noexcept : pNode(node) {}
    ConstIterator& operator++() noexcept {
        pNode = pNode->next_.get();
        return *this;
    }
    bool operator!=(const ConstIterator& other) const noexcept {
        return pNode != other.pNode;
    }
    reference operator*() const noexcept {
        return pNode->value();
    }
    pointer operator->() const noexcept {
        return &(pNode->value());
    }
};

#endif // MYLIST_H