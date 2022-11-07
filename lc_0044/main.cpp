#include <string_view>

#include "../utils/common.hpp"

bool IsMatch(const std::string_view s, const std::string_view p) {
  // After a wildcard, attempt to match next char from
  // `s` with the next char from `p`. If no match, then assume
  // this mismatch is subsumed by previous wildcard.
  auto prev_star{-1}, prev_match_start{-1}, i{0}, j{0};
  const auto sl{s.length()}, pl{p.length()};

  while (i < sl) {
    // tried to match too early, reached end of pattern
    // string but still have characters to match
    if (j == p.length()) {
      goto backtrack;
    }

    // Uncomment this line to see the backtracking process.
    // std::cout << s.substr(i) << " " << p.substr(j) << " " << prev_star <<
    // std::endl;

    // match concrete character from s
    if (p[j] != '*') {
      // character match
      if (p[j] == '?' || p[j] == s[i]) {
        ++i;
        ++j;
      }
      // no match, attempt to backtrack
      // (backtrack means retry matching pattern on later
      // part of s)
      else {
      backtrack:
        // no wildcard to subsume => no match
        if (prev_star == -1) {
          return false;
        }
        i = ++prev_match_start;
        j = prev_star + 1;
      }
    }
    // otherwise, wildcard; set dfs branching point
    else {
      prev_star = j;
      prev_match_start = i;
      ++j;
    }
  }

  // check that there are no unmatched pattern vars
  // except wildcards
  for (; j < pl; ++j) {
    if (p[j] != '*') {
      return false;
    }
  }
  return true;
}

int main() {
  assert(!IsMatch("aa", "a"));
  assert(IsMatch("aa", "*"));
  assert(!IsMatch("cb", "?a"));
  assert(IsMatch("adceb", "*a*b"));
  assert(!IsMatch("acdcb", "a*c?b"));

  return 0;
}
