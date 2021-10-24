#include "binary_search.hpp"

// finds *a* (i.e., *any*) index of `target` appearing in `nums`,
// or -1 if not found
int binary_search(vector<int>& nums, int target) {
        int l, r, m;
        
        for (l = 0, r = nums.size(); l < r; ) {
                m = (l + r) >> 1;
            
                if (nums[m] == target) {
                        return m;
                } else if (nums[m] > target) {
                        r = m;
                } else {
                        l = m+1;
                }
        }
        
        return -1;
}

// find rotation of a rotated sorted array
int find_rotation(vector<int>& nums) {
        int l, r, m, len;

        for (l = 0, r = len = nums.size(); l < r; ) {
                m = (l + r) >> 1;
                
                if (nums[m] < nums[0]) {
                        r = m;
                } else {
                        l = m+1;
                }
        }

        return l % len;
}
