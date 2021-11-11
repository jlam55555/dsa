#include "../utils/common.hpp"

int longestPalindromeSubseq(string s) {
        // indexed by (length,start)
        int dp[1001][1000] = {0};
        int l = s.length();
        
        // palindromes of length 0 and 1 are all possible
        for (int i = 0; i < l; ++i) {
                dp[1][i] = 1;
        }
        
        // check all lengths k=[2,l]
        for (int k = 2; k <= l; ++k) {
            
                // possible start positions j for length k: [0,l-k]
                for (int j = 0; j <= l-k; ++j) {
                
                        int best = max(dp[k-1][j], dp[k-1][j+1]);
                
                        // left, right = (j, j+k-1)
                        if (s[j] == s[j+k-1]) {
                                best = max(best, dp[k-2][j+1]+2);
                        }
                
                        dp[k][j] = best;
                }
        }
        
        return dp[l][0];
}

int main() {
        assert(longestPalindromeSubseq("bbbab") == 4);
        assert(longestPalindromeSubseq("cbbd") == 2);
        assert(longestPalindromeSubseq("eiartkwekaktearismearitkeikeaismariseninaresnartie") == 23);

        cout << "Done." << endl;
        return 0;
}
