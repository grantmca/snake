#ifndef DEQUE_H
#define DEQUE_H

#include <stdexcept>

template <typename T>
class Deque {
public:
  Deque();
  ~Deque();
  void pushFront(const T& value);
  void pushEnd(const T& value);
  T popFront();
  T popEnd();
  int size();
  T& at(int index);

private:
  T* array = nullptr;
  int total_space;
  int occupied_space;
  int front_index;
  int back_index;
  int mid_point;
  void resize();
  bool emptyColision();
};

template <typename T>
Deque<T>::Deque() {
    const int MIN_SIZE = 4; 
    total_space = MIN_SIZE;
    mid_point = MIN_SIZE/2 - 1;
    occupied_space = 0;
    front_index = mid_point;
    back_index = mid_point;
    array = new T[total_space];
}


template <typename T>
Deque<T>::~Deque() {
  delete[] array;
}
#endif // DEQUE_H
