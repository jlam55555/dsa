#include "three_sum.hpp"

#include <vector>

#include "../utils/common.hpp"

// Leetcode 15.
int main() {
  std::vector<int> v1{-1, 0, 1, 2, -1, -4}, v2 = {}, v3 = {0};
  std::vector<std::vector<int>> v1_{{-1, -1, 2}, {-1, 0, 1}};

  assert_eq(dsa::three_sum::ThreeSum(v1), v1_);
  assert_eq(dsa::three_sum::ThreeSum(v2), std::vector<std::vector<int>>{});
  assert_eq(dsa::three_sum::ThreeSum(v3), std::vector<std::vector<int>>{});

  return 0;
}
