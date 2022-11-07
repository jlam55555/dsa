#include <vector>

#include "../utils/common.hpp"

int FindLength(const std::vector<int> &nums1, const std::vector<int> &nums2) {
  // Find maximum length of subarray beginning at nums[i], nums[j].
  int dp[1001][1001]{0};

  auto max_len{0};
  const auto l1{nums1.size()}, l2{nums2.size()};

  // Loop through each starting position of `nums1`.
  for (auto i{0}; i < l1; ++i) {

    // Loop through each starting position of `nums2`.
    for (auto j{0}; j < l2; ++j) {

      if (nums1[i] == nums2[j]) {
        dp[i][j] = 1 + (i && j ? dp[i - 1][j - 1] : 0);
        max_len = std::max(max_len, dp[i][j]);
      }
    }
  }

  return max_len;
}

int main() {
  const std::vector<int> v11{1, 2, 3, 2, 1}, v12{3, 2, 1, 4, 7},
      v21{0, 0, 0, 0, 0}, v22{0, 0, 0, 0, 0};

  assert_eq(FindLength(v11, v12), 3);
  assert_eq(FindLength(v21, v22), 5);

  return 0;
}
