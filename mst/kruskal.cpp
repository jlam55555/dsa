#include "mst.hpp"

#include <algorithm>
#include <vector>

#include "../graph/graph.hpp"
#include "../union_find/union_find.hpp"

namespace dsa::mst {

int Kruskal(std::vector<graph::Edge> &edges) {
  // We don't actually need a graph data structure, we just need
  // a list of weighted edges. `g` only used for counting nodes;
  // we should replace this.
  graph::Graph g{edges};
  union_find::DisjointSet ds{g.Size()};
  auto min_weight{0};

  std::sort(edges.begin(), edges.end());

  for (auto &e : edges) {
    if (ds.Union(e.from, e.to)) {
      min_weight += e.weight;
    }
  }

  return min_weight;
}

} // namespace dsa::mst
