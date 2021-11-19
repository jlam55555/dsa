#include "../utils/common.hpp"

// based on https://leetcode.com/problems/regular-expression-matching/discuss/5684/
// very elegant dp recurrence relations
bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();

        // dp[i][j] is true if s[:i] matches p[:j]
        // i.e., if it is true we can consider matching
        // s[i:] and p[j:]
        bool dp[21][31] = {1};

        // loop through positions i in s, try to find possible
        // matching positions j in p
        for (int i = 0; i <= m; i++) {
                for (int j = 1; j <= n; j++) {
                        // previous character was a wildcard,
                        // current character can be reached in two ways
                        if (p[j - 1] == '*') {
                                dp[i][j] = dp[i][j - 2] 
                                        || (i && dp[i - 1][j] 
                                            && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                        }
                        // previous character was not a wildcard,
                        // current character can be reached if previous characters match
                        else {
                                dp[i][j] = i 
                                        && dp[i - 1][j - 1] 
                                        && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                        }
                }
        }
        return dp[m][n];
}

int main() {
        assert(isMatch("aa", "a") == false);
        assert(isMatch("aa", "a*") == true);
        assert(isMatch("ab", ".*") == true);
        assert(isMatch("aab", "c*a*b") == true);
        assert(isMatch("mississippi", "mis*is*p*.") == false);
        
        cout << "Done." << endl;
        return 0;
}
