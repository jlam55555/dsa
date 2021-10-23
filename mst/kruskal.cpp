#include "mst.hpp"
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
