#include "../utils/common.hpp"

int largestRectangleArea(vector<int>& heights) {
        
        // find the first on the left and right shorter than the current
        int l = heights.size();
        vector<int> left(l), right(l);
        left[0] = -1;
        right[l-1] = l;
        for (int i = 1; i < l; ++i) {
                int p = i-1;
                while (p >= 0 && heights[p] >= heights[i]) {
                        p = left[p];
                }
                left[i] = p;
            
                p = (l-1-i)+1;
                while (p < l && heights[p] >= heights[l-1-i]) {
                        p = right[p];
                }
                right[l-1-i] = p;
        }
        
        // get the maximum size
        int res = INT_MIN;
        for (int i = 0; i < l; ++i) {
                res = max(res, heights[i] * (right[i]-left[i]-1));
        }
        
        return res;
}

int main() {
        vector<int> v1{2,1,5,6,2,3},
                v2{2,4};

        assert(largestRectangleArea(v1) == 10);
        assert(largestRectangleArea(v2) == 4);

        cout << "Done." << endl;
        return 0;
}
