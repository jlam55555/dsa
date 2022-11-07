#include "lis.hpp"

#include <vector>

#include "../binary_search/binary_search.hpp"

namespace dsa::lis {

int LengthOfLis(const std::vector<int> &nums) {
  std::vector<int> dp{};
  auto piles{0};

  for (auto i : nums) {
    // Standard binary search to find first position >= `i`.
    auto pos{dsa::binary_search::BinarySearchGe(dp, i)};
    if (pos == piles) {
      ++piles;
      dp.push_back(0);
    }
    dp[pos] = i;
  }

  return piles;
}

} // namespace dsa::lis
