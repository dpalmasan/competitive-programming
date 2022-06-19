#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <vector>
#include <doctest/doctest.h>
#include "max_subarray_sum.h"


TEST_CASE("Test brute force approach") {
    std::vector<int> arr;
    arr = {-1, 2, 4, -3, 5, 2, -5, 2};
    CHECK(max_subarray_brute(arr) == 10);

    arr = {-5, -4, -3, -2, -1};
    CHECK(max_subarray_brute(arr) == -1);

    arr = {5, 4, 3, 2, 1};
    CHECK(max_subarray_brute(arr) == 15);
}

TEST_CASE("Linear runtime approach") {
    std::vector<int> arr;
    arr = {-1, 2, 4, -3, 5, 2, -5, 2};
    CHECK(max_subarray_linear(arr) == 10);

    arr = {-5, -4, -3, -2, -1};
    CHECK(max_subarray_linear(arr) == -1);

    arr = {5, 4, 3, 2, 1};
    CHECK(max_subarray_linear(arr) == 15);
}