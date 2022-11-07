#include "three_sum.hpp"

#include <algorithm>
#include <vector>
namespace {

// Helper functions. These may be more seamlessly performed using macros, but
// macros are discouraged by the Google style guide.
inline void LSkip(int &l, const int r, const std::vector<int> &nums) {
  while (l < r && nums[l] == nums[l + 1]) {
    ++l;
  }
  ++l;
}

inline void RSkip(const int l, int &r, const std::vector<int> &nums) {
  while (l < r && nums[r] == nums[r - 1]) {
    --r;
  }
  --r;
}

} // namespace

namespace dsa::three_sum {

std::vector<std::vector<int>> ThreeSum(std::vector<int> &nums) {
  std::vector<std::vector<int>> res{};

  // Copy `nums` to allow it to be const, since we need to sort it.
  std::sort(nums.begin(), nums.end());

  // optimization: stop when i>0
  for (auto i{0}; i < int(nums.size()) - 2 && nums[i] <= 0; ++i) {
    // avoid duplicates: if we've already checked this first
    // number, don't repeat it
    if (!i || nums[i] != nums[i - 1]) {

      // standard bi-directional 2-sum sweep
      // invariant: l, r are on the outermost duplicate (if any)
      auto l{i + 1};
      auto r{int(nums.size()) - 1};
      auto t{-nums[i]};
      while (l < r) {
        if (nums[l] + nums[r] == t) {
          res.push_back({nums[i], nums[l], nums[r]});
          LSkip(l, r, nums);
          RSkip(l, r, nums);
        } else if (nums[l] + nums[r] < t) {
          LSkip(l, r, nums);
        } else {
          RSkip(l, r, nums);
        }
      }
    }
  }

  return res;
}

#undef LSKIP
#undef RSKIP

} // namespace dsa::three_sum
