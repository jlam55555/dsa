#include <climits>
#include <vector>

#include "../utils/common.hpp"

int MinSubArrayLen(int target, const std::vector<int> &nums) {
  // Sliding window defined by [l, r] (inclusive).
  auto min_width{INT_MAX};
  for (auto l{0}, r{0}, cur_sum{0}; r < nums.size(); ++r) {
    cur_sum += nums[r];

    // Window start slide right
    while (l < r && cur_sum - nums[l] >= target) {
      cur_sum -= nums[l++];
    }

    // New `min_width`; if condition is false, we must
    // be at the end of the array.
    if (cur_sum >= target) {
      min_width = std::min(min_width, r - l + 1);
    }
  }

  // If min_width == INT_MAX then we haven't found a solution.
  return min_width == INT_MAX ? 0 : min_width;
}

int main() {
  std::vector<int> v1{2, 3, 1, 2, 4, 3}, v2{1, 4, 4},
      v3{1, 1, 1, 1, 1, 1, 1, 1};

  auto targetSum1{7}, targetSum2{4}, targetSum3{11};

  auto res1{MinSubArrayLen(targetSum1, v1)},
      res2{MinSubArrayLen(targetSum2, v2)},
      res3{MinSubArrayLen(targetSum3, v3)};

  assert_eq(res1, 2);
  assert_eq(res2, 1);
  assert_eq(res3, 0);

  return 0;
}
