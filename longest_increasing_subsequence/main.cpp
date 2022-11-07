#include "lis.hpp"

#include <vector>

#include "../utils/common.hpp"

// Leetcode 300.
int main() {
  std::vector<int> v1{10, 9, 2, 5, 3, 7, 101, 18}, v2{0, 1, 0, 3, 2, 3},
      v3{7, 7, 7, 7, 7, 7, 7};

  assert_eq(dsa::lis::LengthOfLis(v1), 4);
  assert_eq(dsa::lis::LengthOfLis(v2), 4);
  assert_eq(dsa::lis::LengthOfLis(v3), 1);

  return 0;
}
