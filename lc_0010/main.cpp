#include <string_view>

#include "../utils/common.hpp"

// Based on:
// https://leetcode.com/problems/regular-expression-matching/discuss/5684/
// Very elegant dp recurrence relations.
bool IsMatch(const std::string_view s, const std::string_view p) {
  const auto m{s.size()}, n{p.size()};

  // `dp[i][j]` is true if `s[:i]` matches `p[:j]`
  // i.e., if it is true we can consider matching
  // `s[i:]` and `p[j:]`
  bool dp[21][31]{1};

  // Loop through positions `i` in `s`, try to find possible
  // matching positions `j` in `p`.
  for (auto i{0}; i <= m; i++) {
    for (auto j{1}; j <= n; j++) {
      // Previous character was a wildcard,
      // current character can be reached in two ways.
      if (p[j - 1] == '*') {
        dp[i][j] = dp[i][j - 2] || (i && dp[i - 1][j] &&
                                    (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
      }
      // Previous character was not a wildcard,
      // current character can be reached if previous characters match
      else {
        dp[i][j] =
            i && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
      }
    }
  }
  return dp[m][n];
}

int main() {
  assert(!IsMatch("aa", "a"));
  assert(IsMatch("aa", "a*"));
  assert(IsMatch("ab", ".*"));
  assert(IsMatch("aab", "c*a*b"));
  assert(!IsMatch("mississippi", "mis*is*p*."));

  return 0;
}
