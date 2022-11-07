#include "knapsack.hpp"

#include <vector>

#include "../utils/common.hpp"

int main(void) {
  std::vector<int> values{60, 100, 120}, weights{10, 20, 30};
  auto cost{50};

  assert_eq(dsa::knapsack::Knapsack01(values, weights, cost), 220);

  return 0;
}
