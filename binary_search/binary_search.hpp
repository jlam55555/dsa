#ifndef DSA_BINARY_SEACH_BINARY_SEARCH_HPP
#define DSA_BINARY_SEACH_BINARY_SEARCH_HPP

#include <optional>
#include <vector>

namespace dsa::binary_search {

// Generalized binary search. Returns the (first) insertion index
// of `target` in `arr`.
//
// In other words, returns the first index `i` such that
// `arr[i] >= target`.
int BinarySearchGe(const std::vector<int> &arr, int target);

// Binary search for equality. Returns `-1` if `target` is not found
// in `arr`.
std::optional<int> BinarySearch(const std::vector<int> &nums, int target);

// Use binary search to find rotation of sorted array
int FindRotation(const std::vector<int> &nums);

} // namespace dsa::binary_search

#endif // DSA_BINARY_SEARCH_BINARY_SEARCH_HPP
