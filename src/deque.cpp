#include <stdexcept>

template <typename T>
class Deque {
public:
  Deque();
  ~Deque();
  void pushFront(const T& value);
  void pushEnd(const T& value);
  void popFront();
  void popEnd();
  int size();
  void reset();
  T& at(int index);

private:
  T* array = nullptr;
  int total_space;
  int occupied_space;
  int front_index;
  int back_index;
  int mid_point;
  void resize();
};

template <typename T>
void Deque<T>::reset () {
  delete[] array;
  const int MIN_SIZE = 4; 
  total_space = MIN_SIZE;
  mid_point = MIN_SIZE/2 - 1;
  occupied_space = 0;
  front_index = mid_point;
  back_index = mid_point;
  array = new T[total_space];
}

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
template <typename T>
void Deque<T>::pushFront (const T& value) {
  if (occupied_space == 0) {
    array[front_index] = value;
    occupied_space = 1;
    return;
  }
  if (front_index - 1 <= 0)  resize(); 
  front_index--;
  array[front_index] = value;
  occupied_space++;
}

template <typename T>
void Deque<T>::pushEnd (const T& value) {
  if (occupied_space == 0) {
    array[back_index] = value;
    occupied_space = 1;
    return;
  }
  if (back_index + 1 >= total_space) resize(); 
  back_index++;
  array[back_index] = value;
  occupied_space++;
}

template <typename T>
void Deque<T>::popFront () {
  if (occupied_space == 0) return;
  if (occupied_space == 1) {
    reset();
    return;
  }
  front_index++;
  occupied_space--;
  return;
}

template <typename T>
void Deque<T>::popEnd () {
  if (occupied_space == 0) return;
  if (occupied_space == 1) {
    reset();
    return;
  }
  back_index--;
  occupied_space--;
  return;
}

template <typename T>
void Deque<T>::resize () {
  // calculate the new size
  int new_total_space = total_space * 2;
  // create the new array
  T* new_array = new T[new_total_space];
  // calculate mid point
  int new_mid_point = new_total_space/2 - 1;
  // Copy Front
  int front_size = mid_point - front_index + 1;
  for (int i = 0; i < front_size; i++) {
    new_array[new_mid_point - i] = array[mid_point - i];
  }
  // Copy End 
  int back_size = back_index - mid_point;
  for (int i = 1; i <=  back_size; i++) {
    new_array[new_mid_point + i] = array[mid_point + i];
  }
  delete[] array;
  array = new_array;
  total_space = new_total_space;
  mid_point = new_mid_point;
  front_index = mid_point - front_size + 1;
  back_index = mid_point + back_size;
}

template <typename T>
T& Deque<T>::at (int i) {
  if (( front_index  + i ) > back_index) throw std::out_of_range("You are out of range");
  return array[front_index  + i];
}

template <typename T>
int Deque<T>::size () {
  return occupied_space;
}
