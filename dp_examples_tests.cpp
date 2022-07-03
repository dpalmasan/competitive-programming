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

TEST_CASE("Max path sum") {
    SUBCASE("Book example") {
        int arr[5][5] = {
            {3, 7, 9, 2, 7},
            {9, 8, 3, 5, 5},
            {1, 7, 9, 8, 5},
            {3, 8, 6, 4, 10},
            {6, 3, 9, 7, 8}
        };
        int **test = new int*[5];
        for (auto i = 0; i < 5; ++i) {
            test[i] = new int[5];
            for (auto j = 0; j < 5; ++j) {
                test[i][j] = arr[i][j];
            }
        }
        CHECK(max_path_sum(test, 5, 5) == 67);
    }

    SUBCASE("Extreme value example example") {
        int arr[5][5] = {
            {3, 7, 9, 2, 7},
            {9, 8, 3, 5, 5},
            {1, 7, 9, 8, 5},
            {3, 8, 6, 4, 10},
            {1000, 3, 9, 7, 8}
        };
        int **test = new int*[5];
        for (auto i = 0; i < 5; ++i) {
            test[i] = new int[5];
            for (auto j = 0; j < 5; ++j) {
                test[i][j] = arr[i][j];
            }
        }
        CHECK(max_path_sum(test, 5, 5) == 1043);
    }
}

TEST_CASE("Knapsack") {
    std::vector<int> arr = {1, 3, 3, 5};
    CHECK(knapsack(arr, 12) == 11);
}
