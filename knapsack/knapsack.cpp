#include "knapsack.hpp"

#include <bitset>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <vector>

namespace dsa::knapsack {

int Knapsack01(const std::vector<int> &items, const std::vector<int> &costs,
               int cost) {
  // `i` = item, `c` = cost
  auto len_items{items.size()};
  auto dp{static_cast<int *>(std::malloc((cost + 1) * sizeof(int)))};

  memset(dp, 0, (cost + 1) * sizeof(int));

  // Knapsack 0/1 algorithm.
  // Optimize in space by alternating between two rows.
  for (auto i{0}; i < len_items; ++i) {
    for (auto c{cost}; c >= 1; --c) {
      dp[c] = std::max(dp[c],
                       costs[i] <= c ? items[i] + dp[c - costs[i]] : INT_MIN);
    }
  }
  auto ans = dp[cost];

  std::free(dp);
  return ans;
}

bool SubsetSumKnapsack(const std::vector<int> &values, int sum) {
  return Knapsack01(values, values, sum) == sum;
}

bool SubsetSumBitwise(const std::vector<int> &values, int sum) {
  auto len_items{values.size()};

  // needs to be a fixed size; may need to adjust based on the problem
  std::bitset<32768> dp{1};

  for (auto i{0}; i < len_items; ++i) {
    for (auto c{sum}; c >= 1; --c) {
      if (values[i] <= c) {
        dp[c] = dp[c] | dp[c - values[i]];
      }
    }
  }

  return dp[sum];
}

bool SubsetSumBitwiseOpt(const std::vector<int> &values, int sum) {
  std::bitset<32768> dp{1};
  for (auto i : values) {
    dp |= dp << i;
  }
  return dp[sum];
}

} // namespace dsa::knapsack
