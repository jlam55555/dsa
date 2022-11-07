#ifndef DSA_UTILS_STRING_HPP
#define DSA_UTILS_STRING_HPP

// helper functions not in the stdlib for strings

#include <string>
#include <string_view>
#include <vector>

#include "./common.hpp"

namespace dsa::utils {

// Sample implementation of `std::string::starts_with()`.
// See also `std::string::rfind()`.
bool StartsWith(const std::string_view s, const std::string_view prefix);

// Split a string by the character delimiter.
std::vector<std::string> StringSplit(const std::string_view s, char delim);

} // namespace dsa::utils

#endif // DSA_UTILS_STRING_HPP
