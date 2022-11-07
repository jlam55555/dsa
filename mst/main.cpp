#include "mst.hpp"

#include <vector>

#include "../graph/graph.hpp"
#include "../utils/common.hpp"

int main() {
  std::vector<dsa::graph::Edge> edges{
      {0, 1, 1}, {0, 2, 9}, {1, 2, 10}, {1, 3, 15}, {2, 3, 11},
      {3, 4, 6}, {4, 5, 9}, {0, 5, 14}, {2, 5, 2},
  };

  assert_eq(dsa::mst::Kruskal(edges), 27);

  return 0;
}
