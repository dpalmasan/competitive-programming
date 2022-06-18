#include <iostream>
#include <vector>

void search(std::vector<int> &permutation, bool *chosen, long unsigned int n) {
    if (permutation.size() == n) {
        std::cout << "{";
        for (auto c : permutation) {
            std::cout << c << " ";
        }
        std::cout << "} ";
    } else {
        for (long unsigned int i = 1; i <= n; ++i) {
            if (!chosen[i]) {
                chosen[i] = true;
                permutation.push_back(i);
                search(permutation, chosen, n);
                chosen[i] = false;
                permutation.pop_back();
            }
        }
    }
}

void permutations(long unsigned int n) {
    std::vector<int> permutation;
    bool chosen[n + 1];
    search(permutation, chosen, n);
}

int main(void) {
    permutations(3);
    return 0;
}
