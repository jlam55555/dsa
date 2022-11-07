#include <climits>
#include <string>
#include <string_view>

#include "../utils/common.hpp"

std::string MinWindow(const std::string_view s, const std::string_view t) {
  if (t.empty()) {
    return 0;
  }

  int hist[256]{0};
  auto unique{0};
  for (auto c : t) {
    if (++hist[c] == 1) {
      ++unique;
    }
  }

  auto min_window{INT_MAX};
  std::string min_win_str{};

  // Sliding window approach:
  // If `unique == 0`, this means the window contains all
  // characters from `t`.
  for (auto l{0}, r{0}; r < s.size(); ++r) {
    // Advance right pointer to include `s[r]`.
    if (--hist[s[r]] == 0) {
      --unique;
    }

    // Try to slide `l` as far right as possible so that the
    // range [l,r] contains all the letters of `t`.
    auto hadMatched{unique == 0};
    while (l <= r && !unique) {
      if (++hist[s[l++]] == 1) {
        ++unique;
      }
    }

    // No `l > r` || no match
    // which means [l-1,r] is the smallest window.
    if (hadMatched) {
      auto win{r - (l - 1) + 1};
      if (win < min_window) {
        min_window = win;
        min_win_str = s.substr(l - 1, r + 1 - (l - 1));
      }
    }
  }

  return min_win_str;
}

int main() {
  assert_eq(MinWindow("ADOBECODEBANC", "ABC"), "BANC");
  assert_eq(MinWindow("a", "a"), "a");
  assert_eq(MinWindow("a", "aa"), "");

  return 0;
}
