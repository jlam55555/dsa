#include "./string.hpp"

// helper function; can also use stdlib `rfind`
// there is a similar function in C++20 stdlib
// but it takes a `basic_string_view` as parameter
bool starts_with(string s, string prefix) {
        if (s.length() < prefix.length()) {
                return false;
        }
        for (int i = 0; i < prefix.length(); ++i) {
                if (s[i] != prefix[i]) {
                        return false;
                }
        }
        return true;
}
