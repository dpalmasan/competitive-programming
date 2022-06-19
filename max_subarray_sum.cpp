#include <iostream>
#include <vector>

int max_subarray_brute(std::vector<int> &arr) {
    int best = arr[0];
    for(uint32_t i = 0; i < arr.size(); ++i) {
        int sum = 0;
        for (uint32_t j = i; j < arr.size(); ++j) {
            sum += arr[j];
            best = std::max(sum, best);
        }
    }
    return best;
}

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
int max_subarray_linear(std::vector<int> &arr) {
    int best = arr[0], sum = arr[0];
    for(uint32_t i = 1; i < arr.size(); ++i) {
        sum = std::max(arr[i], sum + arr[i]);
        best = std::max(sum, best);
    }
    return best;
}

int main(void) {
    std::vector<int> arr = {-1, 2, 4, -3, 5, 2, -5, 2};

    std::cout << "Brute force sol: " << max_subarray_brute(arr) << std::endl;
    std::cout << "Linear sol: " << max_subarray_linear(arr) << std::endl;

    arr = {-5, -4, -3, -2, -1};
    std::cout << "Brute force sol: " << max_subarray_brute(arr) << std::endl;
    std::cout << "Linear sol: " << max_subarray_linear(arr) << std::endl;

    arr = {5, 4, 3, 2, 1};
    std::cout << "Brute force sol: " << max_subarray_brute(arr) << std::endl;
    std::cout << "Linear sol: " << max_subarray_linear(arr) << std::endl;
    return 0;
}
