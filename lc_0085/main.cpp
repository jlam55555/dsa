#include <climits>
#include <vector>

#include "../utils/common.hpp"

// Copied almost verbatim from lc_0084, except vector of chars rather than ints.
int LargestRectangleArea(const std::vector<char> &heights) {
  // Find the first on the left and right shorter than the current
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

// Note: `matrix` is not const.
int MaximalRectangle(std::vector<std::vector<char>> &matrix) {

  // 2-D version of lc_0084
  auto max_rect{INT_MIN};
  const auto m{matrix.size()}, n{m ? matrix[0].size() : 0};

  if (!m || !n) {
    return 0;
  }

  for (auto i{0}; i < m; ++i) {
    for (auto j{0}; j < n; ++j) {
      matrix[i][j] -= '0';
      if (i && matrix[i][j]) {
        matrix[i][j] += matrix[i - 1][j];
      }
    }

    // Perform lc_0084
    max_rect = std::max(max_rect, LargestRectangleArea(matrix[i]));
  }

  return max_rect;
}

int main() {
  std::vector<std::vector<char>> v1{{'1', '0', '1', '0', '0'},
                                    {'1', '0', '1', '1', '1'},
                                    {'1', '1', '1', '1', '1'},
                                    {'1', '0', '0', '1', '0'}},
      v2{}, v3{{'0'}}, v4{{'1'}}, v5{{'0', '0'}};

  assert_eq(MaximalRectangle(v1), 6);
  assert_eq(MaximalRectangle(v2), 0);
  assert_eq(MaximalRectangle(v3), 0);
  assert_eq(MaximalRectangle(v4), 1);
  assert_eq(MaximalRectangle(v5), 0);

  return 0;
}
