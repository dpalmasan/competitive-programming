#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <vector>
#include "sorting_examples.h"


TEST_CASE("Test Has unique function") {
    SUBCASE("Has unique elements") {
        std::vector<int> v = {1, -3, 10, -100, 8, 20};
        CHECK(has_unique_elements(v));
    }

    SUBCASE("Non unique at the end") {
        std::vector<int> v = {20, 1, -3, 10, -100, 8, 20};
        CHECK(!has_unique_elements(v));
    }
}
