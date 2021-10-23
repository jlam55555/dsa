#include "knapsack.hpp"

// calculate the maximum cost of items that fits with cost <= cost
int knapsack_01(::vector<int>& items, ::vector<int>& costs, int cost) {
        // i = item, c = cost
        int len_items = items.size(), i, c, ans;
        
        vector<vector<int>> dp(len_items+1, vector<int>(cost+1));

        // knapsack 0/1 algorithm
        for (i = 0; i < len_items; ++i) {
                for (c = 1; c <= cost; ++c) {
                        if (costs[i] <= c) {
                                dp[i+1][c] = ::max(items[i] + dp[i][c-costs[i]], dp[i][c]);
                        } else {
                                dp[i+1][c] = dp[i][c];
                        }
                }
        }
        ans = dp[len_items][cost];

        return ans;
}

// check if a subset of the values sum to a given number
// subset of knapsack problem where items = weights
bool subset_sum(::vector<int>& values, int sum) {
        return knapsack_01(values, values, sum) == sum;
}
