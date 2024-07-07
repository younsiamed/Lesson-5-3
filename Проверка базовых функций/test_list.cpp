#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include "catch_amalgamated.cpp"
#include "list.hpp"

TEST_CASE("Empty function works correctly", "[Empty]") {
    List list;

    SECTION("New list is empty") {
        REQUIRE(list.Empty() == true);
    }

    SECTION("List with elements is not empty") {
        list.PushBack(1);
        REQUIRE(list.Empty() == false);
    }

    SECTION("List becomes empty after Clear") {
        list.PushBack(1);
        list.Clear();
        REQUIRE(list.Empty() == true);
    }
}

TEST_CASE("Size function works correctly", "[Size]") {
    List list;

    SECTION("New list has size 0") {
        REQUIRE(list.Size() == 0);
    }

    SECTION("Size increases with added elements") {
        list.PushBack(1);
        list.PushBack(2);
        REQUIRE(list.Size() == 2);
    }

    SECTION("Size decreases after elements are removed") {
        list.PushBack(1);
        list.PushBack(2);
        list.PopBack();
        REQUIRE(list.Size() == 1);
    }

    SECTION("Size is 0 after Clear") {
        list.PushBack(1);
        list.PushBack(2);
        list.Clear();
        REQUIRE(list.Size() == 0);
    }
}

TEST_CASE("Clear function works correctly", "[Clear]") {
    List list;

    SECTION("Clear on new list does nothing") {
        list.Clear();
        REQUIRE(list.Empty() == true);
    }

    SECTION("Clear removes all elements") {
        list.PushBack(1);
        list.PushBack(2);
        list.PushBack(3);
        list.Clear();
        REQUIRE(list.Size() == 0);
        REQUIRE(list.Empty() == true);
    }
}
