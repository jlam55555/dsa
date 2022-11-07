#include <algorithm>

#include "../utils/common.hpp"

// Count how many elements of the `m` x `n` multiplication
// table are <= guess. In other words, `guess` is the
// `k`-th largest element in the multiplication table.
int Kth(int m, int n, int guess) {
  auto count{0};
  for (auto i{1}; i <= m; ++i) {
    count += std::min(guess / i, n);
  }
  return count;
}

// Specialized binary search in range [1, m*n].
//
// The way this works is that we can quickly compute how many numbers
// are less than `m` for some guess `m`, and keep guessing until we
// find `m == k` via binary search.
//
// Loop invariant: the `k`-th largest is in [l, r].
// i.e., `m` is at least the `k`-th largest.
int FindKthNumber(int m, int n, int k) {
  auto l{1}, r{m * n};
  while (l < r) {
    auto mid{(l + r) / 2};

    // Loop invariant kept.
    if (Kth(m, n, mid) >= k) {
      r = mid;
    }
    // Loop invariant broken.
    else {
      l = mid + 1;
    }
  }

  return l;
}

int main() {
  assert_eq(FindKthNumber(3, 3, 5), 3);
  assert_eq(FindKthNumber(2, 3, 6), 6);

  return 0;
}
