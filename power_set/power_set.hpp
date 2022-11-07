#ifndef DSA_POWER_SET_HPP
#define DSA_POWER_SET_HPP

#include <vector>

namespace dsa::power_set {

// Get power set of nums, which we assume contains unique elements.
//
// Leetcode 78: Subsets I
std::vector<std::vector<int>> Subsets(const std::vector<int> &nums);

// Get power set of nums, which may contain duplicates
// but don't return any duplicate elements. Sorts nums.
//
// Leetcode 90: Subsets II
std::vector<std::vector<int>> SubsetsDup(std::vector<int> &nums);

} // namespace dsa::power_set

#endif // DSA_POWER_SET_HPP
