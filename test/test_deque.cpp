#include <catch2/catch_test_macros.hpp>
#include "deque.h"

TEST_CASE("CalculatorTest - PushFront", "[Calculator]") {
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

TEST_CASE("CalculatorTest - PushBack", "[Calculator]") {
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

TEST_CASE("CalculatorTest - Popfront", "[Calculator]") {
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

TEST_CASE("CalculatorTest - Popback", "[Calculator]") {
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

