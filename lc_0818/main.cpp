// based on:
// https://leetcode.com/problems/race-car/discuss/124326/
// The recurrence relation is very difficult

#include "../utils/common.hpp"
    
int racecar_rec(vector<int> &dp, int target) {
        if (dp[target] < INT_MAX) {
                return dp[target];
        }
        
        int res = INT_MAX;
        
        // m is the number of forward 'A's,
        // j is the distance moved by the m's
        int m, j, n, k;
        for (m = 1, j = 1; j < target; j = (1 << ++m) - 1) {
            
                // we need to reverse again and move forward
                // there may be no A's in between
                // n and k are analogous to m and j
                for (n = 0, k = 0; k < j; k = (1 << ++n) - 1) {
                        res = min(res, m + 1 + n + 1 + racecar_rec(dp, target - (j - k)));
                }
        }
        
        // account for reversal cases
        res = min(res, m + (j == target ? 0 : 1 + racecar_rec(dp, j - target)));
        
        return dp[target] = res;
}
    
int racecar(int target) {
        vector<int> dp(target+1, INT_MAX);
        dp[0] = 0;      
        return racecar_rec(dp, target);
}

int main() {
        assert(racecar(3) == 2);
        assert(racecar(4) == 5);
        assert(racecar(6) == 5);
        
        cout << "Done." << endl;
        return 0;
}
