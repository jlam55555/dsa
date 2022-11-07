#include <string>
#include <string_view>
#include <unordered_set>
#include <vector>

#include "../utils/common.hpp"
#include "../utils/string.hpp"

bool WordBreak(const std::string_view s,
               const std::vector<std::string> &word_dict,
               std::unordered_set<std::string_view> &searched) {
  // Memoization.
  if (searched.count(s)) {
    return false;
  }

  // Base case; string matches.
  if (s.empty()) {
    return true;
  }

  // Decompose string into word + substd::string, check substd::string
  // recursively
  for (auto &word : word_dict) {
    if (dsa::utils::StartsWith(s, word)) {
      if (WordBreak(s.substr(word.length()), word_dict, searched)) {
        return true;
      }
    }
  }

  searched.insert(s);
  return false;
}

bool WordBreak(std::string_view s, const std::vector<std::string> &word_dict) {
  std::unordered_set<std::string_view> searched{};
  return WordBreak(s, word_dict, searched);
}

int main() {
  std::string s1{"leetcode"}, s2{"applepenapple"}, s3{"catsandog"};
  std::vector<std::string> v1{"leet", "code"}, v2{"apple", "pen"},
      v3{"cats", "dog", "sand", "and", "cat"};

  assert(WordBreak(s1, v1));
  assert(WordBreak(s2, v2));
  assert(!WordBreak(s3, v3));

  return 0;
}
