#include "./kadane.hpp"

#include "../utils/common.hpp"

using dsa::kadane::MaxSubarraySum;

// Leetcode 53.
int main() {
  std::vector<int> v1{-2, 1, -3, 4, -1, 2, 1, -5, 4}, v2{1}, v3{5, 4, -1, 7, 8};

  assert_eq(MaxSubarraySum(v1), 6);
  assert_eq(MaxSubarraySum(v2), 1);
  assert_eq(MaxSubarraySum(v3), 23);

  return 0;
}
