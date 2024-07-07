#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.cpp"
#include "catch_amalgamated.hpp"
#include "list.h"

TEST_CASE("PushBack", "[list]") {
    List list;
    list.PushBack(1);
    list.PushBack(2);
    list.PushBack(3);

    REQUIRE(list.Size() == 3);
    REQUIRE(list.PopBack() == 3);
    REQUIRE(list.PopBack() == 2);
    REQUIRE(list.PopBack() == 1);
    REQUIRE(list.Empty());
}

TEST_CASE("PushFront", "[list]") {
    List list;
    list.PushFront(1);
    list.PushFront(2);
    list.PushFront(3);

    REQUIRE(list.Size() == 3);
    REQUIRE(list.PopFront() == 3);
    REQUIRE(list.PopFront() == 2);
    REQUIRE(list.PopFront() == 1);
    REQUIRE(list.Empty());
}

TEST_CASE("PopBack on empty list", "[list]") {
    List list;
    REQUIRE_THROWS_AS(list.PopBack(), std::runtime_error);
}

TEST_CASE("PopFront on empty list", "[list]") {
    List list;
    REQUIRE_THROWS_AS(list.PopFront(), std::runtime_error);
}

TEST_CASE("Complex scenario", "[list]") {
    List list;
    list.PushBack(1);
    list.PushFront(2);
    list.PushBack(3);
    list.PushFront(4);

    REQUIRE(list.Size() == 4);
    REQUIRE(list.PopFront() == 4);
    REQUIRE(list.PopBack() == 3);
    REQUIRE(list.PopFront() == 2);
    REQUIRE(list.PopBack() == 1);
    REQUIRE(list.Empty());
}
