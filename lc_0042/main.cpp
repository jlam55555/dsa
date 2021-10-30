#include "../utils/common.hpp"

// calculate left and right running sums; find closest running sum in
// each direction: that is the current trapped water height
//
// example: 4,2,0,3,2,5
//
//      +
// +----|
// |  | |
// || |||
// || |||
//
// 444445 maxLeft
// 555555 maxRight
int trap(vector<int>& height) {

        int trapped = 0;
        
        // calculate cumulative maxima from left and right
        vector<int> maxLeft(height.size(), 0), maxRight(height.size(), 0);
        for (int i = 0; i < height.size(); ++i) {
                maxLeft[i] = !i || height[i] > maxLeft[i-1] ? height[i] : maxLeft[i-1];
        }
        for (int i = height.size()-1; i >= 0; --i) {
                maxRight[i] = i==height.size()-1 || height[i] > maxRight[i+1]
                        ? height[i] : maxRight[i+1];
        }
        
        // count trapped water
        for (int i = 0; i < height.size(); ++i) {
                trapped += min(maxLeft[i], maxRight[i]) - height[i];
        }
        
        return trapped;
}

int main() {
        vector<int> v1{0,1,0,2,1,0,1,3,2,1,2,1},
                v2{4,2,0,3,2,5};

        assert(trap(v1) == 6);
        assert(trap(v2) == 9);

        cout << "Done." << endl;
        return 0;
}
