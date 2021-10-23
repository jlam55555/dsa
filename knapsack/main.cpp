#include "knapsack.hpp"

int main(void) {
        cout << "Hello, world!" << endl;

        vector<int> values{60, 100, 120};
        vector<int> weights{10, 20, 30};
        int cost = 50;

        cout << knapsack_01(values, weights, cost) << endl;
        
        return 0;
}
