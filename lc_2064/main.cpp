#include <climits>
#include <cmath>
#include <vector>

#include "../utils/common.hpp"

bool NoSolution(int n, std::vector<int> &quantities, int soln) {
  auto sum{0};
  for (auto i : quantities) {
    sum += std::ceil(float(i) / soln);
  }
  return sum > n;
}

int MinimizedMaximum(int n, std::vector<int> &quantities) {
  auto max_quantity{INT_MIN};
  for (auto i : quantities) {
    max_quantity = std::max(max_quantity, i);
  }

  // Binary search to find solution
  // generalized binary search with nontraditional
  // loop invariant (`NoSolution() == false`).
  auto l{1}, r{max_quantity + 1};

  while (l < r) {
    auto m{(l + r) / 2};
    if (NoSolution(n, quantities, m)) {
      l = m + 1;
    } else {
      r = m;
    }
  }

  return l;
}

int main() {
  auto n1{6}, n2{7}, n3{1};
  std::vector<int> v1{11, 6}, v2{15, 10, 10}, v3{100000};

  assert_eq(MinimizedMaximum(n1, v1), 3);
  assert_eq(MinimizedMaximum(n2, v2), 5);
  assert_eq(MinimizedMaximum(n3, v3), 100000);

  return 0;
}
