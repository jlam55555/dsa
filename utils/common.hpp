// Useful boilerplate.
#ifndef DSA_UTILS_COMMON_HPP
#define DSA_UTILS_COMMON_HPP

// Leetcode does (something like) this, but this violates
// the Google C++ style guide.
// https://google.github.io/styleguide/cppguide.html#Include_What_You_Use
// #include <algorithm>
// #include <bitset>
// #include <climits>
// #include <cmath>
// #include <cstring>
// #include <iostream>
// #include <list>
// #include <map>
// #include <queue>
// #include <set>
// #include <stack>
// #include <unordered_map>
// #include <unordered_set>
// #include <vector>

// Leetcode does this, but this violates the Google
// C++ style guide.
// https://google.github.io/styleguide/cppguide.html#Namespaces
// using namespace std;

#include <cassert>

// Useful for assertions. This can be defined using templates, but then
// the `assert()` macro would not print a useful error message.
// (It will print "assertion failed: a == b" rather than the true values
// of `a` and `b`.)
#define assert_eq(a, b) assert((a) == (b))

// Check that the C++ version is >= C++17. This matches the
// current Google style guide target version.
// `static_assert()` isn't standardized before C++11, but that's
// okay because we're checking C++ version anyways.
static_assert(__cplusplus >= 201703L, "Must be at least C++17");

#endif // DSA_UTILS_COMMON_HPP
