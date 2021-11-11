#include "../utils/common.hpp"

bool noSolution(int n, vector<int>& quantities, int soln) {
        int sum = 0;
        for (auto i : quantities) {
                sum += ceil((float)i / soln);
        }
        return sum > n;
}
    
int minimizedMaximum(int n, vector<int>& quantities) {
        
        int maxQuantity = INT_MIN;
        for (auto i : quantities) {
                maxQuantity = max(maxQuantity, i);
        }
        
        // binary search to find solution
        // generalized binary search with nontraditional
        // loop invariant (noSolution() is false)
        int l = 1, r = maxQuantity+1, m;
        
        while (l < r) {
                m = (l + r) / 2;
                if (noSolution(n, quantities, m)) {
                        l = m + 1;
                } else {
                        r = m;
                }
        }
        
        return l;
}

int main() {
        int n1 = 6, n2 = 7, n3 = 1;
        vector<int> v1{11,6}, v2{15,10,10}, v3{100000};

        assert(minimizedMaximum(n1, v1) == 3);
        assert(minimizedMaximum(n2, v2) == 5);
        assert(minimizedMaximum(n3, v3) == 100000);

        cout << "Done." << endl;
        return 0;
}
