#include "../utils/common.hpp"

bool isMatch(string s, string p) {
        // after a wildcard, attempt to match next char from
        // s with the next char from p. if no match, then assume
        // this mismatch is subsumed by previous wildcard
        int prevStar = -1, prevMatchStart = -1, i = 0, j = 0, sl = s.length(), pl = p.length();
        
        while (i < sl) {
                // tried to match too early, reached end of pattern
                // string but still have characters to match
                if (j == p.length()) {
                        goto backtrack;
                }
            
                // Uncomment this line to see the backtracking process.
                // cout << s.substr(i) << " " << p.substr(j) << " " << prevStar << endl;
            
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
                                if (prevStar == -1) {
                                        return false;
                                }
                                i = ++prevMatchStart;
                                j = prevStar + 1;
                        }
                }
                // otherwise, wildcard; set dfs branching point
                else {
                        prevStar = j;
                        prevMatchStart = i;
                        ++j;
                }
        }
        
        // check that there are no unmatched pattern vars
        // except wildcards
        for (; j < p.length(); ++j) {
                if (p[j] != '*') {
                        return false;
                }
        }
        return true;
}

int main() {
        assert(isMatch("aa", "a") == false);
        assert(isMatch("aa", "*") == true);
        assert(isMatch("cb", "?a") == false);
        assert(isMatch("adceb", "*a*b") == true);
        assert(isMatch("acdcb", "a*c?b") == false);
        
        cout << "Done." << endl;
        return 0;
}
