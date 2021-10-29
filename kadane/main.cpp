#include "../utils/common.hpp"
#include "./kadane.hpp"

// lc_53
int main() {
        vi v1{-2,1,-3,4,-1,2,1,-5,4},
                v2{1},
                v3{5,4,-1,7,8};

        assert(max_subarray_sum(v1) == 6);
        assert(max_subarray_sum(v2) == 1);
        assert(max_subarray_sum(v3) == 23);

        cout << "Done." << endl;
        return 0;
}
