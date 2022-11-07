#include <vector>

#include "../utils/common.hpp"

// Calculate left and right running sums; find closest running sum in
// each direction: that is the current trapped water height
//
// Example: 4,2,0,3,2,5
//
//      +
// +----|
// |  | |
// || |||
// || |||
//
// 444445 maxLeft
// 555555 maxRight
int Trap(const std::vector<int> &height) {
  auto trapped{0};

  // Calculate cumulative maxima from left and right.
  std::vector<int> max_left(height.size(), 0), max_right(height.size(), 0);
  for (auto i{0}; i < height.size(); ++i) {
    max_left[i] =
        !i || height[i] > max_left[i - 1] ? height[i] : max_left[i - 1];
  }
  for (auto i{int(height.size()) - 1}; i >= 0; --i) {
    max_right[i] = i == height.size() - 1 || height[i] > max_right[i + 1]
                       ? height[i]
                       : max_right[i + 1];
  }

  // Count trapped water.
  for (auto i{0}; i < height.size(); ++i) {
    trapped += std::min(max_left[i], max_right[i]) - height[i];
  }

  return trapped;
}

int main() {
  std::vector<int> v1{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}, v2{4, 2, 0, 3, 2, 5};

  assert_eq(Trap(v1), 6);
  assert_eq(Trap(v2), 9);

  return 0;
}
