#include <string_view>

#include "../utils/common.hpp"

// Dynamic programming problem with fixed lookahead.
int NumDecodings(const std::string_view s) {
  int dp[2]{1, 0};

  // Loop invariant:
  // `dp[0]` is the number of known paths to `s[i]`.
  // `dp[1]` is the number of known paths to `s[i+1]`.
  for (auto i{0}; i < s.length(); ++i) {
    // Calculate (new) ways to get to `s[i+1]`,
    // ways to get to `s[i+2]` knowing `s[i]`, `s[i+1]`.
    auto c{s[i]};
    auto prev{dp[0]}, curr{dp[1]};

    dp[0] = curr;
    dp[1] = 0;

    if (c == '0') {
      // No ways to advance.
    } else {
      dp[0] += prev;

      if (i < s.length() - 1 && (c < '2' || c == '2' && s[i + 1] < '7')) {
        dp[1] += prev;
      }
    }
  }

  return dp[0];
}

int main() {
  assert_eq(NumDecodings("12"), 2);
  assert_eq(NumDecodings("226"), 3);
  assert_eq(NumDecodings("0"), 0);
  assert_eq(NumDecodings("06"), 0);
  assert_eq(NumDecodings("12321113213213112211231"), 7344);

  return 0;
}
