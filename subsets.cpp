#include <iostream>
#include <vector>

void search(std::vector<int> &subset, int k, int n) {
    if (k == n + 1) {
        std::cout << "{";
        for (auto i: subset) {
            std::cout << i << " ";
        }
        std::cout << "} ";
        return;
    }
    subset.push_back(k);
    search(subset, k + 1, n);
    subset.pop_back();
    search(subset, k + 1, n);
}

void subsets(int n) {
    std::vector<int> v;
    search(v, 1, n);
}

int main(void) {
    subsets(5);
    return 0;
}
