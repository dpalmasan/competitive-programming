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

std::vector<std::pair<int, int>> schedule_events(std::vector<std::pair<int, int>>& events) {
    std::vector<std::pair<int, int>> out;
    std::sort(events.begin(), events.end(), [](std::pair<int, int>& a, std::pair<int, int>& b) { return a.second < b.second; });
    int curr_end_time = 0;
    for (auto event : events) {
        if (event.first >= curr_end_time) {
            out.push_back(event);
            curr_end_time = event.second;
        }
    }
    return out;
}