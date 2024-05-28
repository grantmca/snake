#include <iostream>
#include "deque.h"
#include <raylib.h>

int main () {
  Deque<int> deq;
  int a = 6;
  deq.pushEnd(a);

  return 0;
}
