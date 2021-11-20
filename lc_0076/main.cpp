#include "../utils/common.hpp"

string minWindow(string s, string t) {
        if (t.empty()) {
            return 0;
        }
        
        int hist[256] = {0}, unique = 0;
        for (char c : t) {
            if (++hist[c] == 1) {
                ++unique;
            }
        }
        
        int minWindow = INT_MAX;
        string minWinStr = "";
        
        // sliding window approach
        // if unique == 0, this means the window contains all
        // characters from t
        int l, r;
        for (l = r = 0; r < s.size(); ++r) {
            // advance right pointer to include s[r]
            if (--hist[s[r]] == 0) {
                --unique;
            }
            
            // try to slide l as far right as possible so that the
            // range [l,r] contains all the letters of t
            bool hadMatched = unique == 0;
            while (l <= r && !unique) {
                if (++hist[s[l++]] == 1) {
                    ++unique;
                }
            }
            
            // now l > r || no match
            // which means [l-1,r] is the smallest window
            if (hadMatched) {
                int win = r-(l-1)+1;
                if (win < minWindow) {
                    minWindow = win;
                    minWinStr = s.substr(l-1, r+1-(l-1));
                }
            }
        }
        
        return minWinStr;
    }

int main() {
        assert(minWindow("ADOBECODEBANC", "ABC") == "BANC");
        assert(minWindow("a", "a") == "a");
        assert(minWindow("a", "aa") == "");
        DONE
}
