#include "./scc.hpp"

#include <vector>

#include "../graph/graph.hpp"
#include "../utils/common.hpp"

int main() {
  // Example from:
  // https://www.topcoder.com/thrive/articles/kosarajus-algorithm-for-strongly-connected-components
  dsa::graph::Graph g{{{8, 10},
                       {0, 1},
                       {1, 2},
                       {2, 0},
                       {2, 3},
                       {3, 4},
                       {4, 5},
                       {5, 6},
                       {6, 7},
                       {4, 7},
                       {6, 4}}};

  auto actual{dsa::scc::Kosaraju(g)};
  std::vector<std::vector<int>> expected{{1, 2, 0}, {3}, {5, 6, 4}, {7}};

  assert_eq(actual, expected);

  return 0;
}
