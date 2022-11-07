#include <vector>

#include "../knapsack/knapsack.hpp"
#include "../utils/common.hpp"

// This is basically the knapsack problem. We need to see
// if we can find a subset of nums that sums to half of
// the total sum.
bool CanPartition(const std::vector<int> &nums) {
  auto sum{0};
  for (auto i : nums) {
    sum += i;
  }

  if (sum % 2) {
    return false;
  }

  // return dsa::knapsack::SubsetSumKnapsack(nums, sum>>1);
  // return dsa::knapsack::SubsetSumBitwise(nums, sum>>1);
  return dsa::knapsack::SubsetSumBitwiseOpt(nums, sum >> 1);
}

int main(void) {
  std::vector<int> tc1{1, 5, 11, 5};
  assert(CanPartition(tc1));

  std::vector<int> tc2{1, 2, 3, 5};
  assert(!CanPartition(tc2));

  return 0;
}
