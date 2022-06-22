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