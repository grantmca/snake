#include <algorithm>
#include <iostream>
#include <catch2/catch_test_macros.hpp>
#include <ostream>
#include "deque.cpp"

TEST_CASE("Deque::pushFront - Verify elements are added to the front", "[Deque]") {
  Deque<int> deq;
  deq.pushFront(1);
  deq.pushFront(2);
  deq.pushFront(3);
  deq.pushFront(4);
  REQUIRE(deq.at(0) == 4);
  REQUIRE(deq.at(1) == 3);
  REQUIRE(deq.at(2) == 2);
  REQUIRE(deq.at(3) == 1);
}

TEST_CASE("Deque::pushEnd - Verify elements are added to the end", "[Deque]") {
  Deque<int> deq;
  deq.pushEnd(1);
  deq.pushEnd(2);
  deq.pushEnd(3);
  deq.pushEnd(4);
  REQUIRE(deq.at(0) == 1);
  REQUIRE(deq.at(1) == 2);
  REQUIRE(deq.at(2) == 3);
  REQUIRE(deq.at(3) == 4);
}

TEST_CASE("Deque::popFront - Verify correct element removal from the front", "[Deque]") {
  Deque<int> deq;
  deq.pushEnd(1);
  REQUIRE(deq.size() == 1);
  deq.pushEnd(2);
  REQUIRE(deq.size() == 2);
  deq.pushEnd(3);
  REQUIRE(deq.size() == 3);
  deq.pushEnd(4);
  REQUIRE(deq.size() == 4);
  deq.popFront();
  REQUIRE(deq.size() == 3);
  REQUIRE(deq.at(0) == 2);
  deq.popFront();
  REQUIRE(deq.at(0) == 3);
  REQUIRE(deq.size() == 2);
  deq.popFront();
  REQUIRE(deq.size() == 1);
  deq.popFront();
  REQUIRE(deq.size() == 0);
}

TEST_CASE("Deque::popEnd - Verify correct element removal from the back", "[Deque]") {
  Deque<int> deq;
  deq.pushEnd(1);
  deq.pushEnd(2);
  deq.pushEnd(3);
  deq.pushEnd(4);
  deq.popEnd();
  REQUIRE(deq.at(0) == 1);
  deq.popEnd();
  REQUIRE(deq.at(0) == 1);

  deq.popEnd();
  deq.popEnd();
  REQUIRE(deq.size() == 0);
}

TEST_CASE("Deque::pushAndPopOperations - Verify size adjustments and element access", "[Deque]") {
  Deque<int> deq;
  deq.pushFront(1);
  REQUIRE(deq.size() == 1);
  deq.pushFront(2);
  REQUIRE(deq.size() == 2);
  deq.pushFront(3);
  REQUIRE(deq.size() == 3);
  deq.pushFront(4);
  REQUIRE(deq.size() == 4);

  deq.popFront();
  REQUIRE(deq.size() == 3);
  deq.popFront();
  REQUIRE(deq.size() == 2);
  deq.popFront();
  REQUIRE(deq.size() == 1);
  deq.popFront();
  REQUIRE(deq.size() == 0);

  deq.pushEnd(1);
  REQUIRE(deq.size() == 1);
  deq.pushEnd(2);
  REQUIRE(deq.size() == 2);
  deq.pushEnd(3);
  REQUIRE(deq.size() == 3);
  deq.pushEnd(4);
  REQUIRE(deq.size() == 4);

  deq.popEnd();
  REQUIRE(deq.size() == 3);
  deq.popEnd();
  REQUIRE(deq.size() == 2);
  deq.popEnd();
  REQUIRE(deq.size() == 1);
  deq.popEnd();
  REQUIRE(deq.size() == 0);
}

TEST_CASE("Deque::snakeTest - Verify content after mixed push and pop operations", "[Deque]") {
  Deque<int> deq;

  deq.pushFront(1);
  deq.pushFront(2);
  deq.pushFront(3);
  deq.pushFront(4);
  deq.popEnd();
  deq.pushFront(1);
  deq.popEnd();
  deq.pushFront(2);
  deq.popEnd();
  deq.pushFront(3);
  deq.popEnd();

  deq.pushFront(4);
  deq.pushEnd(4);
  deq.pushEnd(4);
  deq.pushEnd(4);
  deq.pushEnd(4);
  deq.pushEnd(4);
  deq.pushEnd(4);
  deq.pushEnd(4);
  deq.pushEnd(4);
  deq.pushEnd(4);

  REQUIRE(deq.at(0) == 4);
  REQUIRE(deq.at(1) == 3);
  REQUIRE(deq.at(2) == 2);
  REQUIRE(deq.at(3) == 1);
  REQUIRE(deq.at(4) == 4);
  REQUIRE(deq.at(5) == 4);
  REQUIRE(deq.at(6) == 4);
  REQUIRE(deq.at(7) == 4);
  REQUIRE(deq.at(8) == 4);
  REQUIRE(deq.at(9) == 4);
  REQUIRE(deq.at(10) == 4);
  REQUIRE(deq.at(11) == 4);
  REQUIRE(deq.at(12) == 4);
  REQUIRE(deq.size() == 13);
}
