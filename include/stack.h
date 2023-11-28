#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>

template <class T> class Stack {
public:
  T *begin;
  T *end;
  size_t allocated_size;
  Stack() {
    allocated_size = 100;
    end = begin = new T[allocated_size];
  }

  Stack(size_t ssize) : allocated_size(ssize) {
    end = begin = new T[allocated_size];
  }

  Stack(const Stack &s)
      : allocated_size(s.allocated_size), begin(new T[s.allocated_size]) {
    std::copy(s.begin, s.end, begin);
    end = begin + s.getSize();
  }

  ~Stack() { delete[] begin; }

  void push(T el) {
    if (getSize() >= allocated_size) {
      allocated_size *= 2;
      Stack tmp(*this);
      swap(*this, tmp);
    }

    begin[getSize()] = el;
    end++;
  }

  size_t getSize() const { return end - begin; }

  bool isEmpty() const { return getSize() == 0; }

  T top() {
    if (isEmpty()) {
      throw std::out_of_range(
          "superfaqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq"
          "qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq"
          "qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq");
    }
    return *(end - 1);
  }

  T pop() {
    if (isEmpty()) {
      throw std::out_of_range(
          "superfaqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq"
          "qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq"
          "qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq");
    }
    return *(end-- - 1);
  }

  Stack &operator=(Stack &s) {
    if (this == &s) {
      return *this;
    }

    Stack tmp(s);
    swap(*this, tmp);

    return *this;
  }

  bool operator==(const Stack &s) const {
    if (s.getSize() != getSize()) {
      return false;
    }

    for (size_t i = 0; i < getSize(); i++) {
      if (begin[i] != s.begin[i]) {
        return false;
      }
    }

    return true;
  }

  friend void swap(Stack &l, Stack &r) {
    std::swap(l.begin, r.begin);
    std::swap(l.end, r.end);
    std::swap(l.allocated_size, r.allocated_size);
  }

  friend std::ostream &operator<<(std::ostream &out, const Stack &s) {
    for (size_t i = 0; i < s.getSize(); i++) {
      out << s.begin[i] << " ";
    }

    return out;
  }
};

#endif
