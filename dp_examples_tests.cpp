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

TEST_CASE("Test coin problem, count solutions") {
    SUBCASE("Negative sum") {
        std::vector<int> coins = {1, 2, 5};
        int sum = -3;
        CHECK(coin_problem_count_solutions(coins, sum) == 0);
    }

    SUBCASE("Empty set (sum = 0)") {
        std::vector<int> coins = {1, 3, 4};
        int sum = 0;
        CHECK(coin_problem_count_solutions(coins, sum) == 1);
    }

    SUBCASE("DP Solution") {
        std::vector<int> coins = {1, 3, 4};
        int sum = 5;
        CHECK(coin_problem_count_solutions(coins, sum) == 6);
    }
}

TEST_CASE("Longest increasing subsequence") {
    std::vector<int> arr = {6, 2, 5, 1, 7, 4, 8, 3};
    CHECK(longest_inc_sub(arr) == 4);
}