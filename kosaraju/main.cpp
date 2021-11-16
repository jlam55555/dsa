#include "../utils/common.hpp"
#include "./kosaraju.hpp"

int main() {
        // example from:
        // https://www.topcoder.com/thrive/articles/kosarajus-algorithm-for-strongly-connected-components
        graph g{{{8,10},
                 {0,1},
                 {1,2},
                 {2,0},
                 {2,3},
                 {3,4},
                 {4,5},
                 {5,6},
                 {6,7},
                 {4,7},
                 {6,4}
                }};

        auto act = kosaraju(g);
        vector<vector<int>> exp = {{1,2,0},{3},{5,6,4},{7}};

        assert(act == exp);

        cout << "Done." << endl;
        return 0;
}
