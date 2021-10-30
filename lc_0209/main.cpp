#include "../utils/common.hpp"

int minSubArrayLen(int target, vector<int>& nums) {
        
        // left and right of sliding window (inclusive)
        int l, r, cur_sum, min_width;
        
        for (l = r = cur_sum = 0, min_width = INT_MAX; r < nums.size(); ++r) {
                cur_sum += nums[r];
            
                // window start slide right
                while (l < r && cur_sum-nums[l] >= target) {
                        cur_sum -= nums[l++];
                }
            
                // new min_width; if condition is false, we must
                // be at  the end of the array
                if (cur_sum >= target) {
                        min_width = min(min_width, r-l+1);
                }
        }
        
        // if min_width == INT_MAX then we haven't found a solution
        return min_width == INT_MAX ? 0 : min_width;
}

int main() {
        vector<int> v1{2,3,1,2,4,3},
                v2{1,4,4},
                v3{1,1,1,1,1,1,1,1};

        int targetSum1 = 7, targetSum2 = 4, targetSum3 = 11;

        int res1 = minSubArrayLen(targetSum1, v1),
                res2 = minSubArrayLen(targetSum2, v2),
                res3 = minSubArrayLen(targetSum3, v3);

        assert(res1 == 2);
        assert(res2 == 1);
        assert(res3 == 0);
        
        cout << "Done." << endl;
        return 0;
}
