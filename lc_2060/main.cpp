#include "../utils/common.hpp"

// dp edit distance problem
// based on https://leetcode.com/problems/check-if-an-original-string-exists-given-two-encoded-strings/discuss/1550012/Python3-dp

// get possible lengths
// for a number with digits a, b, c:
// single digit a -> a
// two digits ab -> ab or a+b
// three digits abc -> abc or ab+c or a+bc or a+b+c
vector<int> getPossibleLengths(string s) {
        vector<int> res{stoi(s)};
        if (s.length() == 2) {
                res.push_back(stoi(s.substr(0,1)) + stoi(s.substr(1,1)));
        } else if (s.length() == 3) {
                res.push_back(stoi(s.substr(0,1)) + stoi(s.substr(1,2)));
                res.push_back(stoi(s.substr(0,2)) + stoi(s.substr(2,1)));
                res.push_back(stoi(s.substr(0,1)) + stoi(s.substr(1,1)) + stoi(s.substr(2,1)));
        }
        return res;
}
    
// i: current position in s1
// j: current position in s2
// paddingDiff: signed offset due to padding between; if positive, means
//    that s2 has a positive number of offset bytes relative to s1
//    from the current position
bool dfs(unordered_set<int> dp[41][41],
         string &s1, string &s2, int i, int j, int paddingDiff) {
        
        // memoization: path already visited
        if (dp[i][j].count(paddingDiff)) {
                return false;
        }
        
        // base case: end reached
        if (i == s1.length() && j == s2.length()) {
                if (paddingDiff != 0) {
                        goto fail;
                }
                return true;
        }
        
        // add padding (numbers) on s1 or s2
        if (isdigit(s1[i])) {
                int k = i; // k will point to first char after number
                while (k<s1.length() && isdigit(s1[k])) ++k;
                for (auto len : getPossibleLengths(s1.substr(i, k-i))) {
                        if (dfs(dp, s1, s2, k, j, paddingDiff-len)) {
                                return true;
                        }
                }
                goto fail;
        } else if (isdigit(s2[j])) {
                int k = j; // k will point to first char after number
                while (k<s2.length() && isdigit(s2[k])) ++k;
                for (auto len : getPossibleLengths(s2.substr(j, k-j))) {
                        if (dfs(dp, s1, s2, i, k, paddingDiff+len)) {
                                return true;
                        }
                }
                goto fail;
        }
        // no padding difference, consume next letter
        else if (paddingDiff == 0) {
                if (i == s1.length() || j == s2.length() || s1[i] != s2[j]) {
                        goto fail;
                }
                return dfs(dp, s1, s2, i+1, j+1, paddingDiff);
        }
        // s1 has some relative padding; j needs to catch up
        else if (paddingDiff < 0) {
                if (j == s2.length()) {
                        goto fail;
                }
                return dfs(dp, s1, s2, i, j+1, paddingDiff+1);
        }
        // s2 has some relative padding; i needs to catch up
        else {
                if (i == s1.length()) {
                        goto fail;
                }
                return dfs(dp, s1, s2, i+1, j, paddingDiff-1);
        }
        
fail:
        dp[i][j].insert(paddingDiff);
        return false;
}
    
bool possiblyEquals(string s1, string s2) {
        unordered_set<int> dp[41][41];
        return dfs(dp, s1, s2, 0, 0, 0);
}

int main() {
        string s11 = "internationalization", s12 = "i18n",
                s21 = "l123e", s22 = "44",
                s31 = "a5b", s32 = "c5b",
                s41 = "112s", s42 = "g841",
                s51 = "ab", s52 = "a2";

        assert(possiblyEquals(s11, s12) == true);
        assert(possiblyEquals(s21, s22) == true);
        assert(possiblyEquals(s31, s32) == false);
        assert(possiblyEquals(s41, s42) == true);
        assert(possiblyEquals(s51, s52) == false);

        cout << "Done." << endl;
        return 0;
}
