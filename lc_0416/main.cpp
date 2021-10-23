#include "../utils/common.hpp"
#include "../knapsack/knapsack.hpp"

bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto i : nums) {
                sum += i;
        }

        if (sum % 2) {
                return false;
        }

        // return subset_sum_knapsack(nums, sum>>1);
        // return subset_sum_bitwise(nums, sum>>1);
        return subset_sum_bitwise_opt(nums, sum>>1);
}

int main(void) {
        auto tc1 = vector<int>{1,5,11,5};
        assert(canPartition(tc1) == true);

        auto tc2 = vector<int>{1,2,3,5};
        assert(canPartition(tc2) == false);

        cout << "Done." << endl;
        return 0;
}
