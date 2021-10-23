#include "../utils/common.hpp"
#include "mst.hpp"

int main(void) {
        ::vector<graph::edge> edges{
                {0, 1, 1},
                {0, 2, 9},
                {1, 2, 10},
                {1, 3, 15},
                {2, 3, 11},
                {3, 4, 6},
                {4, 5, 9},
                {0, 5, 14},
                {2, 5, 2},
        };

        assert(kruskal(edges) == 27);

        cout << "Done." << endl;
        return 0;
}
