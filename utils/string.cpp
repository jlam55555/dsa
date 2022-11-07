#include <string>
#include <string_view>
#include <vector>

#include "./string.hpp"

namespace dsa::utils {

bool StartsWith(const std::string_view s, const std::string_view prefix) {
  if (s.length() < prefix.length()) {
    return false;
  }
  for (auto i{0}; i < prefix.length(); ++i) {
    if (s[i] != prefix[i]) {
      return false;
    }
  }
  return true;
}

std::vector<std::string> StringSplit(const std::string_view s, char delim) {
  auto prev{0}, pos{-1};
  std::vector<std::string> res{};
  while ((pos = s.find(delim, prev)) != -1) {
    res.emplace_back(s.substr(prev, pos - prev));
    prev = pos + 1; // Skip past the delimiter
  }
  res.emplace_back(s.substr(prev, pos - prev));
  return res;
}

} // namespace dsa::utils
