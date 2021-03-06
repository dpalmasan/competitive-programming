#include <vector>
#include <limits>
#include <iostream>


const int INF = std::numeric_limits<int>::max();


int coin_problem(const std::vector<int>& coins, const int& sum) {

    if (sum <= 0) {
        return 0;
    }

    std::vector<int> dp_table;
    dp_table.reserve(sum + 1);
    dp_table[0] = 0;
    for (auto i = 1; i <= sum; ++i) {
        dp_table[i] = INF;
        for (auto coin: coins) {
            if (i - coin >= 0)  {
                dp_table[i] = std::min(1 + dp_table[i - coin], dp_table[i]);
            }
        }
    }
    return dp_table[sum];
}

int coin_problem_count_solutions(const std::vector<int>& coins, const int& sum) {

    if (sum < 0) {
        return 0;
    }

    if (sum == 0) {
        return 1;
    }

    std::vector<int> dp_table;
    dp_table.reserve(sum + 1);
    dp_table[0] = 1;
    for (auto i = 1; i <= sum; ++i) {
        dp_table[i] = 0;
        for (auto coin: coins) {
            if (i - coin >= 0)  {
                dp_table[i] += dp_table[i - coin];
            }
        }
    }
    return dp_table[sum];
}

int longest_inc_sub(const std::vector<int>& arr) {
    std::vector<int> dp;
    dp.reserve(arr.size());
    int best = 0;
    for (auto k = 0; k < arr.size(); ++k) {
        dp[k] = 1;
        for (auto i = 0; i < k; ++i) {
            if (arr[i] < arr[k]) {
                dp[k] = std::max(dp[k], dp[i] + 1);
            }
        }
        best = std::max(best, dp[k]);
    }
    return best;
}

int max_path_sum(int **arr, const int& m, const int& n) {
    int **sum = new int*[m];
    for (auto i = 0; i < m; ++i) {
        sum[i] = new int[n];
        for (auto j = 0; j < n; ++j) {
            sum[i][j] = std::max((j <= 0) ? 0 : sum[i][j - 1], (i <= 0) ? 0: sum[i - 1][j]) + arr[i][j];
        }
    }
    return sum[m - 1][n - 1];
}

int knapsack(std::vector<int>& weights, const int& sum) {
    bool *possible = new bool[sum + 1];
    possible[0] = true;
    int count = 0;
    for (auto k = 0; k < weights.size(); ++k) {
        for (auto x = sum - weights[k]; x >=0; --x) {
            possible[x + weights[k]] |= possible[x];
        }
    }

    for (auto x = 0; x <= sum; ++x) {
        if (possible[x]) {
            count += 1;
        }
    }
    return count;
}
