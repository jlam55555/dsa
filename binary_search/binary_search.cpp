#include "binary_search.hpp"

// general standard binary search: binary_search_gt(arr, target)
// returns first j such that arr[j] >= target; (note: not equality):
// it is possible that j == target.size(), in which case target
// is greater than every element
int binary_search_gt(vector<int>& arr, int target) {
        int l = 0, r = arr.size(), m;
        // loop invariant: target index is in [arr[l],arr[r]] (inclusive range)
        // at end of loop, l == r
        while (l < r) {
                m = (l + r) / 2;
                // invariant broken; search larger numbers (exclusive);
                // result in (m, r]
                if (arr[m] < target) {
                        l = m+1;
                }
                // invariant held; result in [l,m]
                else {
                        r = m;
                }
        }
        return l;
}

// condensed version of the above, w/o commentary
// not exported b/c this is a copy of the above
int binary_search_gt_condensed(vector<int>& a, int t) {
        int l, r, m;
        for (l = 0, r = a.size(); l != r; ) {
                m = (l + r) >> 1;
                if (a[l] < t) l = m+1;
                else r = m;
        }
        return l;
}

// binary search for equality in terms of binary_search_gt (above)
int binary_search(vector<int>& arr, int target) {
        int i = binary_search_gt(arr, target);
        return i == arr.size() || arr[i] != target ? -1 : i;
}
 
// easy to understand binary search to find an element
// equal to `target` in nums, or `-1` otherwise
// (easy to understand because we don't have to worry as much about
// relation (<, <=, >, >=) if simply checking for equality)
int binary_search_simple(vector<int>& nums, int target) {
        int l, r, m;
        
        for (l = 0, r = nums.size(); l < r; ) {
                m = (l + r) / 2;
            
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
