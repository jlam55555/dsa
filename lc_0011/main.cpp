#include "../utils/common.hpp"

int maxArea(vector<int>& arr) {
        int l = 0, r = arr.size()-1, maxVolume = 0;
        
        while (l < r) {
                maxVolume = max(maxVolume, (r-l)*min(arr[l], arr[r]));
                if (arr[l] < arr[r]) {
                        ++l;
                } else {
                        --r;
                }
        }
        
        return maxVolume;
}

int main() {
        vector<int> v1{1,8,6,2,5,4,8,3,7},
                v2{1,1},
                v3{4,3,2,1,4},
                v4{1,2,1};

        assert(maxArea(v1) == 49);
        assert(maxArea(v2) == 1);
        assert(maxArea(v3) == 16);
        assert(maxArea(v4) == 2);

        cout << "Done." << endl;
        return 0;
}
