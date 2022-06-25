#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <vector>
#include "dp_examples.h"


TEST_CASE("Test coin problem") {
    SUBCASE("Greedy works") {
        std::vector<int> coins = {1, 2, 5};
        int sum = 12;
        CHECK(coin_problem(coins, sum) == 3);
    }

    SUBCASE("Greedy does not work") {
        std::vector<int> coins = {1, 3, 4};
        int sum = 6;
        CHECK(coin_problem(coins, sum) == 2);
    }
}