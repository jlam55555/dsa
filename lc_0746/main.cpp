#include <vector>

#include "../utils/common.hpp"

int MinCostClimbingStairs(std::vector<int> &cost) {
  // Only have to keep track of the previous two elements.
  //
  // Note that the problem statement slightly simplifies the
  // implementation by saying that we can start from either of the
  // first two steps; that means that the cost for the second step
  // is 0, rather than `cost[0]`.
  const auto len{cost.size()};
  auto c{0};

  for (auto a{0}, b{0}, i{2}; i <= len; ++i) {
    c = std::min(a + cost[i - 2], b + cost[i - 1]);
    a = b;
    b = c;
  }

  return c;
}

int main(void) {
  std::vector<int> v1{10, 15, 20}, v2{1, 100, 1, 1, 1, 100, 1, 1, 100, 1};

  assert_eq(MinCostClimbingStairs(v1), 15);
  assert_eq(MinCostClimbingStairs(v2), 6);

  return 0;
}
