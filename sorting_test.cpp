#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include "sorting.h"


bool is_sorted(int* arr, std::size_t n) {
    for (std::size_t i = 0; i < n - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

TEST_CASE("Test bubble sort") {
    int arr[8] = {1, 3, 8, 2, 9, 2, 5, 6};
    bubble_sort(arr, 8);
    CHECK(is_sorted(arr, 8));
}

TEST_CASE("Test merge sort") {
    SUBCASE("Merge intertwined arrays") {
        int arr[6] = {1, 3, 5, 2, 4, 6};
        __merge(arr, 0, 5, 5 / 2);
        CHECK(is_sorted(arr, 6));
    }

    SUBCASE("Merge all left") {
        int arr[6] = {1, 2, 3, -3, -2, -1};
        __merge(arr, 0, 5, 5 / 2);
        CHECK(is_sorted(arr, 6));
    }

    SUBCASE("Merge all right") {
        int arr[6] = {-3, -2, -1, 1, 2, 3};
        __merge(arr, 0, 5, 5 / 2);
        CHECK(is_sorted(arr, 6));
    }

    SUBCASE("Sort array") {
        int arr[8] = {1, 3, 8, 2, 9, 2, 5, 6};
        merge_sort(arr, 8);
        CHECK(is_sorted(arr, 8));
    }
}

TEST_CASE("Test count sort") {
    int arr[10] = {25, 15, 8, 10, 6, 3, 0, 30, 15, 15};
    count_sort(arr, 10, 1000);
    CHECK(is_sorted(arr, 10));
}