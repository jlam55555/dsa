#include <string>
#include <string_view>
#include <unordered_set>
#include <vector>

#include "../utils/common.hpp"

// Dynamic programming edit distance problem, based on:
// https://leetcode.com/problems/check-if-an-original-std::string-exists-given-two-encoded-std::strings/discuss/1550012/Python3-dp

// Get possible lengths for a number with digits a, b, c:
// - single digit a -> a
// - two digits ab -> ab or a+b
// - three digits abc -> abc or ab+c or a+bc or a+b+c
std::vector<int> GetPossibleLengths(const std::string_view str) {
  std::string s{str};
  std::vector<int> res{std::stoi(s)};
  if (s.length() == 2) {
    res.push_back(std::stoi(s.substr(0, 1)) + std::stoi(s.substr(1, 1)));
  } else if (s.length() == 3) {
    res.push_back(std::stoi(s.substr(0, 1)) + std::stoi(s.substr(1, 2)));
    res.push_back(std::stoi(s.substr(0, 2)) + std::stoi(s.substr(2, 1)));
    res.push_back(std::stoi(s.substr(0, 1)) + std::stoi(s.substr(1, 1)) +
                  std::stoi(s.substr(2, 1)));
  }
  return res;
}

// i: current position in s1
// j: current position in s2
// padding_diff: signed offset due to padding between; if positive, means
//    that s2 has a positive number of offset bytes relative to s1
//    from the current position
bool Dfs(std::unordered_set<int> dp[41][41], const std::string_view s1,
         const std::string_view s2, int i, int j, int padding_diff) {

  // Memoization: path already visited.
  if (dp[i][j].count(padding_diff)) {
    return false;
  }

  // Base case: end reached.
  if (i == s1.length() && j == s2.length()) {
    if (padding_diff) {
      goto fail;
    }
    return true;
  }

  // Add padding (numbers) on `s1` or `s2`.
  if (std::isdigit(s1[i])) {
    auto k{i}; // `k` will point to first char after number.
    while (k < s1.length() && std::isdigit(s1[k])) {
      ++k;
    }
    for (auto len : GetPossibleLengths(s1.substr(i, k - i))) {
      if (Dfs(dp, s1, s2, k, j, padding_diff - len)) {
        return true;
      }
    }
    goto fail;
  } else if (std::isdigit(s2[j])) {
    auto k{j}; // `k` will point to first char after number.
    while (k < s2.length() && std::isdigit(s2[k])) {
      ++k;
    }
    for (auto len : GetPossibleLengths(s2.substr(j, k - j))) {
      if (Dfs(dp, s1, s2, i, k, padding_diff + len)) {
        return true;
      }
    }
    goto fail;
  }
  // No padding difference, consume next letter.
  else if (!padding_diff) {
    if (i == s1.length() || j == s2.length() || s1[i] != s2[j]) {
      goto fail;
    }
    return Dfs(dp, s1, s2, i + 1, j + 1, padding_diff);
  }
  // `s1` has some relative padding; `j` needs to catch up.
  else if (padding_diff < 0) {
    if (j == s2.length()) {
      goto fail;
    }
    return Dfs(dp, s1, s2, i, j + 1, padding_diff + 1);
  }
  // `s2` has some relative padding; `i` needs to catch up.
  else {
    if (i == s1.length()) {
      goto fail;
    }
    return Dfs(dp, s1, s2, i + 1, j, padding_diff - 1);
  }

fail:
  dp[i][j].insert(padding_diff);
  return false;
}

bool PossiblyEquals(const std::string_view s1, const std::string_view s2) {
  std::unordered_set<int> dp[41][41];
  return Dfs(dp, s1, s2, 0, 0, 0);
}

int main() {
  const std::string s11{"internationalization"}, s12{"i18n"}, s21{"l123e"},
      s22{"44"}, s31{"a5b"}, s32{"c5b"}, s41{"112s"}, s42{"g841"}, s51{"ab"},
      s52{"a2"};

  assert(PossiblyEquals(s11, s12));
  assert(PossiblyEquals(s21, s22));
  assert(!PossiblyEquals(s31, s32));
  assert(PossiblyEquals(s41, s42));
  assert(!PossiblyEquals(s51, s52));

  return 0;
}
