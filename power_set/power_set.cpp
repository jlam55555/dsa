#include "power_set.hpp"

#include <algorithm>
#include <vector>

namespace dsa::power_set {

// Type alias for convenience. This file is painful otherwise.
using vi = std::vector<int>;
using vvi = std::vector<vi>;

void SubsetsRec(vvi &res, vi &stk, const vi &nums, int i) {
  if (i == nums.size()) {
    res.push_back(stk);
    return;
  }

  // Don't include element
  SubsetsRec(res, stk, nums, i + 1);

  // Include element
  stk.push_back(nums[i]);
  SubsetsRec(res, stk, nums, i + 1);
  stk.pop_back();
}

void SubsetsRecDup(vvi &res, vi &stk, const vi &nums, vi &counts, int i) {
  if (i == nums.size()) {
    res.push_back(stk);
    return;
  }

  // Include repeated element from 0 to counts[i] times.
  for (auto j{0}; j <= counts[i]; ++j) {
    SubsetsRecDup(res, stk, nums, counts, i + 1);
    stk.push_back(nums[i]);
  }

  for (auto j{0}; j <= counts[i]; ++j) {
    stk.pop_back();
  }
}

} // namespace dsa::power_set

namespace dsa::power_set {

vvi Subsets(const vi &nums) {
  vvi res{};
  vi stk{};
  SubsetsRec(res, stk, nums, 0);
  return res;
}

vvi SubsetsDup(vi &nums) {
  vvi res{};
  vi stk{}, nums_uniq{}, counts{};
  int cur_pos{-1};

  std::sort(nums.begin(), nums.end());

  for (auto i{0}; i < nums.size(); ++i) {
    if (i && nums[i] == nums[i - 1]) {
      ++counts[cur_pos];
    } else {
      nums_uniq.push_back(nums[i]);
      counts.push_back(1);
      ++cur_pos;
    }
  }

  SubsetsRecDup(res, stk, nums_uniq, counts, 0);
  return res;
}

} // namespace dsa::power_set
