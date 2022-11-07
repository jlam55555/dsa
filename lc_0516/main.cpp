#include <string_view>

#include "../utils/common.hpp"

int LongestPalindromeSubseq(const std::string_view s) {
  // Indexed by (length,start)
  int dp[1001][1000]{0};
  const auto l{s.length()};

  // Palindromes of length 0 and 1 are all possible.
  for (auto i{0}; i < l; ++i) {
    dp[1][i] = 1;
  }

  // Check all lengths `k`=[2,l]
  for (auto k{2}; k <= l; ++k) {
    // Possible start positions `j` for length `k`: [0,l-k]
    for (auto j{0}; j <= l - k; ++j) {
      auto best = std::max(dp[k - 1][j], dp[k - 1][j + 1]);
      // left, right = (j, j+k-1)
      if (s[j] == s[j + k - 1]) {
        best = std::max(best, dp[k - 2][j + 1] + 2);
      }
      dp[k][j] = best;
    }
  }

  return dp[l][0];
}

int main() {
  assert_eq(LongestPalindromeSubseq("bbbab"), 4);
  assert_eq(LongestPalindromeSubseq("cbbd"), 2);
  assert_eq(LongestPalindromeSubseq(
                "eiartkwekaktearismearitkeikeaismariseninaresnartie"),
            23);

  return 0;
}
