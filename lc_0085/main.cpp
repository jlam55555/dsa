#include "../utils/common.hpp"

// copied almost verbatim from lc_0084, except vector of chars rather than ints
int largestRectangleArea(vector<char>& heights) {
        
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

    
int maximalRectangle(vector<vector<char>>& matrix) {
        
        // 2-D version of lc_0084
        int maxRect = INT_MIN, m = matrix.size(), n = m ? matrix[0].size() : 0;
        
        if (!m || !n) {
                return 0;
        }
        
        for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                        matrix[i][j] -= '0';
                        if (i && matrix[i][j]) {
                                matrix[i][j] += matrix[i-1][j];
                        }
                }
            
                // perform lc_0084
                maxRect = max(maxRect, largestRectangleArea(matrix[i]));
        }
        
        return maxRect;
        
}

int main() {
        vector<vector<char>> v1{
                {'1','0','1','0','0'},
                {'1','0','1','1','1'},
                {'1','1','1','1','1'},
                {'1','0','0','1','0'}},
                v2{},
                v3{{'0'}},
                v4{{'1'}},
                v5{{'0','0'}};

        assert(maximalRectangle(v1) == 6);
        assert(maximalRectangle(v2) == 0);
        assert(maximalRectangle(v3) == 0);
        assert(maximalRectangle(v4) == 1);
        assert(maximalRectangle(v5) == 0);
        
        cout << "Done." << endl;
        return 0;
}
