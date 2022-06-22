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
