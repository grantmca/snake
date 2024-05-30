#include <catch2/catch_test_macros.hpp>
#include "deque.cpp"

TEST_CASE("DequeTest - PushFront", "[Deque]") {
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

TEST_CASE("DequeTest - PushBack", "[Deque]") {
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

TEST_CASE("DequeTest - Popfront", "[Deque]") {
  Deque<int> deq;
  deq.pushEnd(1);
  deq.pushEnd(2);
  deq.pushEnd(3);
  deq.pushEnd(4);
  deq.popFront();
  deq.popFront();
  REQUIRE(deq.at(0) == 3);
  REQUIRE(deq.at(1) == 4);
}

TEST_CASE("DequeTest - Popback", "[Deque]") {
  Deque<int> deq;
  deq.pushEnd(1);
  deq.pushEnd(2);
  deq.pushEnd(3);
  deq.pushEnd(4);
  deq.popEnd();
  deq.popEnd();
  REQUIRE(deq.at(0) == 1);
  REQUIRE(deq.at(1) == 2);
}

TEST_CASE("DequeTest - Snake Test", "[Deque]") {
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
  REQUIRE(deq.at(13) == 4);
}
