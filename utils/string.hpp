#ifndef DSA_UTILS_STRING_HPP
#define DSA_UTILS_STRING_HPP

// helper functions not in the stdlib for strings

#include "./common.hpp"

bool starts_with(string s, string prefix);
vector<string> string_split(string& s, char delim);

#endif
