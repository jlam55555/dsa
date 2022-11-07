#include "./kadane.hpp"

#include <climits>
#include <vector>

namespace dsa::kadane {

int MaxSubarraySum(const std::vector<int> &nums) {
  auto max_sum{INT_MIN}, cur_sum{0};
  for (auto i : nums) {
    cur_sum = i + std::max(cur_sum, 0);
    max_sum = std::max(cur_sum, max_sum);
  }
  return max_sum;
}

} // namespace dsa::kadane
