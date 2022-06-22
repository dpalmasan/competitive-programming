#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <vector>
#include "sorting_examples.h"


TEST_CASE("Test has unique function") {
    SUBCASE("Has unique elements") {
        std::vector<int> v = {1, -3, 10, -100, 8, 20};
        CHECK(has_unique_elements(v));
    }

    SUBCASE("Non unique at the end") {
        std::vector<int> v = {20, 1, -3, 10, -100, 8, 20};
        CHECK(!has_unique_elements(v));
    }
}

TEST_CASE("Test max customers at restaurant") {
    std::vector<std::pair<int, int>> times = { {0, 4}, {1, 3}, {5, 7} ,{2, 6} };
    CHECK(maximum_customers(times) == 3);
}

TEST_CASE("Test scheduling events") {
    SUBCASE("Average instance") {
        std::vector<std::pair<int, int>> v = {{3, 8}, {1, 4}, {5, 7}, {0, 2}}, expected = {{0, 2}, {5, 7}};
        CHECK(schedule_events(v) == expected);
    }

    SUBCASE("Event with short duration") {
        std::vector<std::pair<int, int>> v = {{6, 9}, {1, 7}, {8, 15}}, expected = {{1, 7}, {8, 15}};
        CHECK(schedule_events(v) == expected);
    }

    SUBCASE("Event with early end") {
        std::vector<std::pair<int, int>> v = {{0, 20}, {2, 5}, {6, 10}}, expected = {{2, 5}, {6, 10}};
        CHECK(schedule_events(v) == expected);
    }
}