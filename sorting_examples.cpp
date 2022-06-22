#include <algorithm>
#include <vector>


bool has_unique_elements(std::vector<int>& v) {
    std::sort(v.begin(), v.end());
    for (auto i = v.begin(); i < v.end() - 1; ++i) {
        if (i[0] == i[1]) {
            return false;
        }
    }
    return true;
}

int maximum_customers(std::vector<std::pair<int, int>>& times) {
    auto *times_int = new int[times.size() * 2];
    int max_count = 0, curr_count = 0, k = 0;
    for (auto time : times) {
        times_int[k++] = time.first;
        times_int[k++] = -time.second;
    }
    std::sort(times_int, times_int + 2*times.size(), [](int a, int b) { return abs(a) < abs(b); });
    for (auto i = 0; i < times.size() * 2; ++i) {
        if (times_int[i] >= 0) {
            curr_count++;
        } else {
            curr_count--;
        }
        max_count = std::max(max_count, curr_count);
    }
    return max_count;
}