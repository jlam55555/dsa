#include "../utils/common.hpp"
#include "../binary_search/binary_search.hpp"

// lc_0300

// this algorithm is also known as the "patience sort", because it
// provides a general O(n log n) sorting algorithm (using a heap-based
// K-way merge), and solves the "Patience" game optimally

// also the possibility for returning the longest increasing subsequence
// by maintaining backpointers; the following only stores the length
// of the longest increasing subsequence

// patience sort for longest increasing subsequence
int lengthOfLIS(vector<int>& nums) {
        vector<int> dp{};
        int piles = 0;
        
        for (auto& i : nums) {
                // standard binary search to find first position
                // greater than or equal to i
                int pos = binary_search_gt(dp, i);
                if (pos == piles) {
                        ++piles;
                        dp.push_back(0);
                }
                dp[pos] = i;
        }
        
        return piles;
}

int main() {
        vector<int> v1{10,9,2,5,3,7,101,18},
                v2{0,1,0,3,2,3},
                v3{7,7,7,7,7,7,7};

        assert(lengthOfLIS(v1) == 4);
        assert(lengthOfLIS(v2) == 4);
        assert(lengthOfLIS(v3) == 1);
        
        cout << "Done." << endl;
        return 0;
}
