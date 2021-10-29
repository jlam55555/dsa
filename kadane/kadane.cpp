#include "./kadane.hpp"

// a.k.a. maximum (non-empty) subarray sum
// algorithm is called Kadane's algorithm
int max_subarray_sum(vector<int> &nums) {
        int max_sum = INT_MIN, cur_sum = 0;
        for (auto i : nums) {
                cur_sum = i + max(cur_sum, 0);
                max_sum = max(cur_sum, max_sum);
        }
        return max_sum;
}
