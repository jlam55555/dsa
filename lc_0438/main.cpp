#include <string>
#include <string_view>
#include <vector>

#include "../utils/common.hpp"

// `s` is the haystack, `p` is the needle.
std::vector<int> FindAnagrams(const std::string_view s,
                              const std::string_view p) {
  // Get frequencies of characters in p.
  int freq_map[26]{0};
  auto letter_count{0};
  for (auto c : p) {
    if (++freq_map[c - 'a'] == 1) {
      ++letter_count;
    }
  }

  std::vector<int> res{};
  if (s.length() < p.length()) {
    return res;
  }

  // Build initial counts, for the first `p.length()` letters of `s`.
  for (auto i{0}; i < p.length(); ++i) {
    if (--freq_map[s[i] - 'a'] == 0) {
      --letter_count;
    }
  }

  std::vector<int> matches{};
  if (!letter_count) {
    matches.push_back(0);
  }

  // To detect whether a word is correct, count how many letters
  // match between the letter frequencies of `p` and `s[i:i+p.length()]`.
  // The number of different letters between these two distributions
  // is recorded in `letter_count`. If `letter_count == 0`, then we've
  // found an anagram of `p` in `s[i:i+p.length()]`.
  //
  // Technically this could be combined with the previous `if` statement
  // but this is a nice separation.
  for (auto i{0}; i < s.length() - p.length(); ++i) {
    // Add a letter, check if that letter has the correct count.
    if (!--freq_map[s[i + p.length()] - 'a']) {
      --letter_count;
    }
    // Remove a letter, check if that letter lost the correct count.
    if (++freq_map[s[i] - 'a'] == 1) {
      ++letter_count;
    }

    // Check if all letters have their correct count.
    if (!letter_count) {
      matches.push_back(i + 1);
    }
  }

  return matches;
}

int main() {
  const std::string s1{"cbaebabacd"}, s2{"abab"};
  const std::string p1{"abc"}, p2{"ab"};
  const std::vector<int> v1{0, 6}, v2{0, 1, 2};

  assert_eq(FindAnagrams(s1, p1), v1);
  assert_eq(FindAnagrams(s2, p2), v2);

  return 0;
}
