#include "./power_set.hpp"

void subsets_rec(vvi& res, vi& stk, vi& nums, int i) {
        if (i == nums.size()) {
                res.push_back(stk);
                return;
        }
        
        // don't include element
        subsets_rec(res, stk, nums, i+1);
        
        // include element
        stk.push_back(nums[i]);
        subsets_rec(res, stk, nums, i+1);
        stk.pop_back();
}
    
vvi subsets(vi& nums) {
        vvi res{};
        vi stk{};
        subsets_rec(res, stk, nums, 0);
        return res;
}
