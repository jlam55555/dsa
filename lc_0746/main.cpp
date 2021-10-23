#include "../utils/common.hpp"

int minCostClimbingStairs(vector<int>& cost) {
        // only have to keep track of the previous two elements;
        // note that the problem statement slightly simplifies the
        // implementation by saying that we can start from either of the
        // first two steps; that means that the cost for the second step
        // is 0, rather than `cost[0]`
        int a, b, c, i, len = cost.size();
        
        for (int i = 2, a = b = c = 0; i <= len; ++i) {
                c = min(a+cost[i-2], b+cost[i-1]);
                a = b;
                b = c;
        }
        
        return c;
}

int main(void) {
        vector<int>
                v1{10,15,20},
                v2{1,100,1,1,1,100,1,1,100,1};
        
        assert(minCostClimbingStairs(v1) == 15);
        assert(minCostClimbingStairs(v2) == 6);

        cout << "Done." << endl;
        return 0;
}
