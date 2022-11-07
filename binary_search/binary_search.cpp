#include "binary_search.hpp"

#include <optional>
#include <vector>

namespace dsa::binary_search {

int BinarySearchGe(const std::vector<int> &arr, int target) {
  // We try to find the insertion index `i`, the first index such that
  // `arr[i] >= target`.
  //
  // This is a two-pointer/window approach. The loop invariant we hold is
  // that `i` lies in the (inclusive) range [l, r]. We choose a test point
  // in the middle, `m`, and modify the window to maintain the invariant.
  // At the end, `l == r`, and thus `i == l == r`.
  int l{0}, r(arr.size());
  while (l < r) {
    auto m{(l + r) / 2};
    // Invariant is broken; search larger numbers (exclusive);
    // `i` lies in (m, r].
    if (arr[m] < target) {
      l = m + 1;
    }
    // Invariant is held; search smaller numbers (inclusive);
    // `i` lies in [l, m].
    else {
      r = m;
    }
  }
  return l;
}

namespace {

// Condensed version of the above, w/o commentary.
// This isn't exported b/c this is a copy of the above.
// This probably violates the Google style guide in too many ways.
int BinarySearchGeCondensed(const std::vector<int> &a, int t) {
  int l{0}, r(a.size()), m{};
  while (l < r) {
    m = (l + r) >> 1;
    a[m] < t ? l = m + 1 : r = m;
  }
  return l;
}

} // namespace

std::optional<int> BinarySearch(const std::vector<int> &arr, int target) {
  auto i{BinarySearchGe(arr, target)};
  return i == arr.size() || arr[i] != target ? std::nullopt : std::optional(i);
}

namespace {

// This binary search is easier to understand without thinking
// about invariants. We don't have to think as hard about < vs. <=
// since we check for equality directly. However, this only checks
// for equality and does not generalize to the insertion index.
std::optional<int> BinarySearchSimple(const std::vector<int> &nums,
                                      int target) {
  auto l{0};
  auto r{nums.size()};
  while (l < r) {
    auto m{(l + r) / 2};

    if (nums[m] == target) {
      return m;
    } else if (nums[m] > target) {
      r = m - 1;
    } else {
      l = m + 1;
    }
  }

  // At this point, l == r.
  if (l < nums.size() && nums[l] == target) {
    return l;
  }
  return {};
}

} // namespace

// Find rotation of a rotated sorted array
int FindRotation(const std::vector<int> &nums) {
  auto len{nums.size()};
  auto l{0};
  auto r{len};

  while (l < r) {
    auto m{(l + r) >> 1};

    if (nums[m] < nums[0]) {
      r = m;
    } else {
      l = m + 1;
    }
  }

  return l % len;
}

} // namespace dsa::binary_search
