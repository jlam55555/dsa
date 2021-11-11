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

vector<string> string_split(string& s, char delim) {
        int prev = 0, pos;
        vector<string> res{};
        while ((pos = s.find(delim, prev)) != -1) {
                res.push_back(s.substr(prev, pos-prev));
                prev = pos+1;   // skip past the delimiter
        }
        res.push_back(s.substr(prev, pos-prev));
        return res;
}
