#include "utils/md_array.hpp"
#include "knapsack.hpp"

// calculate the maximum cost of items that fits with cost <= cost
int knapsack_01(::vector<int>& items, ::vector<int>& costs, int cost) {
        // i = item, c = cost
        int len_items = items.size(),
                *dp = (int *) malloc((cost+1)*sizeof(int)),
                i, c, ans;

        memset(dp, 0, (cost+1)*sizeof(int));
        
        // knapsack 0/1 algorithm
        // optimize in space by alternating between two rows
        for (i = 0; i < len_items; ++i) {
                for (c = cost; c >= 1; --c) {
                        dp[c] = ::max(dp[c],
                                      costs[i] <= c
                                      ? items[i] + dp[c-costs[i]]
                                      : INT_MIN);
                }
        }
        ans = dp[cost];

        free(dp);
        return ans;
}

// check if a subset of the values sum to a given number
// subset of knapsack problem where items = weights
// (unoptimized version using full knapsack)
bool subset_sum_knapsack(::vector<int>& values, int sum) {
        return knapsack_01(values, values, sum) == sum;
}

// more optimal version using a bitset; don't need separate weights
// and values anymore, only need to indicate "true" if a particular sum
// can be created from a subset
bool subset_sum_bitwise(::vector<int>& values, int sum) {
        int len_items = values.size(), i, c;

        // needs to be a fixed size; may need to adjust based on the problem
        bitset<32768> dp{1};

        for (i = 0; i < len_items; ++i) {
                for (c = sum; c >= 1; --c) {
                        if (values[i] <= c) {
                                dp[c] = dp[c] | dp[c-values[i]];
                        }
                }
        }

        return dp[sum];
}

// a more efficient version of the above; two ways we can think about this:
// 1. draw out a table of the above, and realize how we are getting from
//    one row to the other
// 2. think about how we are doing it: we are basically taking the sum of
//    an element and everything before it; we can do this in parallel using
//    a SHL (add a fixed value to everything) and an OR (combine results)
bool subset_sum_bitwise_opt(::vector<int>& values, int sum) {
        bitset<32768> dp{1};
        for (auto i : values) {
                dp |= dp << i;
        }
        return dp[sum];
}
