#include "utils/md_array.hpp"
#include "knapsack.hpp"

// calculate the maximum cost of items that fits with cost <= cost
int knapsack_01(::vector<int>& items, ::vector<int>& costs, int cost) {
        // i = item, c = cost
        int len_items = items.size(),
                **dp = (int **) alloc_2d(2, cost+1, sizeof(int), true),
                i, c, ans;
        
        // knapsack 0/1 algorithm
        // optimize in space by alternating between two rows
        for (i = 0; i < len_items; ++i) {
                for (c = 1; c <= cost; ++c) {
                        dp[(i+1)%2][c] = ::max(dp[i%2][c],
                                             costs[i] <= c
                                             ? items[i] + dp[i%2][c-costs[i]]
                                             : INT_MIN);
                }
        }
        ans = dp[i%2][cost];

        // cleanup
        free_2d((void **) dp, 2);
        
        return ans;
}

// check if a subset of the values sum to a given number
// subset of knapsack problem where items = weights
bool subset_sum(::vector<int>& values, int sum) {
        return knapsack_01(values, values, sum) == sum;
}
