#include <unordered_map>
#include <vector>

#include "../utils/common.hpp"

int NumSubmatrixSumTarget(std::vector<std::vector<int>> &matrix, int target) {
  const auto m{matrix.size()}, n{matrix[0].size()};

  // Calculate row cumsums.
  for (auto i{0}; i < m; ++i) {
    for (auto j{1}; j < n; ++j) {
      matrix[i][j] += matrix[i][j - 1];
    }
  }

  // Loop over ranges in one dimension.
  auto res{0};
  for (auto i{0}; i < n; ++i) {
    for (auto j{i}; j < n; ++j) {

      // Consider the "column" that is the sum of
      // all columns in range [i,j].
      // Now find all target sums.
      std::unordered_map<int, int> seen{{0, 1}};
      for (auto k{0}, cur_sum{0}; k < m; ++k) {
        cur_sum += matrix[k][j] - (i ? matrix[k][i - 1] : 0);
        res += seen[cur_sum - target];
        ++seen[cur_sum];
      }
    }
  }

  return res;
}

int main() {
  std::vector<std::vector<int>> v1{{0, 1, 0}, {1, 1, 1}, {0, 1, 0}},
      v2{{1, -1}, {-1, 1}}, v3{{904}};

  assert_eq(NumSubmatrixSumTarget(v1, 0), 4);
  assert_eq(NumSubmatrixSumTarget(v2, 0), 5);
  assert_eq(NumSubmatrixSumTarget(v3, 0), 0);

  return 0;
}
