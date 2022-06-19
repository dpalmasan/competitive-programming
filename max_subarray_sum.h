#pragma once

#include <vector>

int max_subarray_brute(std::vector<int>&);

/**
 * @brief Return maximum contiguous sum of a subarray in the array.
 * 
 * This is O(N), at each time we have two possible choices:
 *      1. We pick the element
 *      2. We add the element
 * In this fashion we are always computing the maximum subarray sum
 * ending in index i, for all i.
 * 
 * @param arr 
 * @return int 
 */
int max_subarray_linear(std::vector<int>&);