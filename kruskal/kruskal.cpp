#include "../utils/common.hpp"
#include "../graph/graph.hpp"
#include "../union_find/union_find.hpp"

// don't actually need a graph data structure, just need
// a list of weighted edges
int kruskal(::vector<graph::edge>& edges) {
        // `g` only used for counting nodes; should replace this
        graph g{edges};
        union_find uf{g.size()};
        int min_weight = 0;

        sort(edges.begin(), edges.end());

        for (auto e : edges) {
                if (uf.unio(e.from, e.to)) {
                        min_weight += e.weight;
                }
        }

        return min_weight;
}

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
