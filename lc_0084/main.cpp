#include <climits>
#include <vector>

#include "../utils/common.hpp"

int LargestRectangleArea(const std::vector<int> &heights) {
  // Find the first on the left and right shorter than the current.
  const auto l{heights.size()};
  std::vector<int> left(l), right(l);
  left[0] = -1;
  right[l - 1] = l;
  for (auto i{1}; i < l; ++i) {
    auto p{i - 1};
    while (p >= 0 && heights[p] >= heights[i]) {
      p = left[p];
    }
    left[i] = p;

    p = (l - 1 - i) + 1;
    while (p < l && heights[p] >= heights[l - 1 - i]) {
      p = right[p];
    }
    right[l - 1 - i] = p;
  }

  // Get the maximum size.
  auto res{INT_MIN};
  for (auto i{0}; i < l; ++i) {
    res = std::max(res, heights[i] * (right[i] - left[i] - 1));
  }

  return res;
}

int main() {
  std::vector<int> v1{2, 1, 5, 6, 2, 3}, v2{2, 4};

  assert_eq(LargestRectangleArea(v1), 10);
  assert_eq(LargestRectangleArea(v2), 4);

  return 0;
}
