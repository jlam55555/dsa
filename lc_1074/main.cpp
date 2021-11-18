#include "../utils/common.hpp"

int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        
        // calculate row cumsums
        for (int i = 0; i < m; ++i) {
                for (int j = 1; j < n; ++j) {
                        matrix[i][j] += matrix[i][j-1];
                }
        }
        
        // loop over ranges in one dimension
        int res = 0;
        for (int i = 0; i < n; ++i) {
                for (int j = i; j < n; ++j) {
                
                        // consider the "column" that is the sum of
                        // all columns in range [i,j]
                        // now find all target sums
                        unordered_map<int,int> seen{{0, 1}};
                        int curSum = 0;
                        for (int k = 0; k < m; ++k) {
                                curSum += matrix[k][j] - (i ? matrix[k][i-1] : 0);
                                res += seen[curSum-target];
                                ++seen[curSum];
                        }
                
                }
        }
        
        return res;
}

int main() {
        vector<vector<int>>
                v1{{0,1,0},{1,1,1},{0,1,0}},
                v2{{1,-1},{-1,1}},
                v3{{904}};

        assert(numSubmatrixSumTarget(v1, 0) == 4);
        assert(numSubmatrixSumTarget(v2, 0) == 5);
        assert(numSubmatrixSumTarget(v3, 0) == 0);

        cout << "Done." << endl;
        return 0;
}
