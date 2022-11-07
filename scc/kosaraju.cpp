#include "scc.hpp"

#include <stack>
#include <vector>

#include "../graph/graph.hpp"

namespace {

// `nodes_` is private within `Graph`, so pass in `nodes_` directly.
// `dsa::kosaraju::Kosaraju` is a friend of `Graph`, so it can access `nodes_`,
// but these helper functions are not friends.
void DfsForward(const std::vector<dsa::graph::Node> &g, int node,
                std::vector<bool> &visited, std::stack<int> &stk) {
  // Don't revisit nodes.
  if (visited[node]) {
    return;
  }
  visited[node] = true;

  // Recurse through descendants.
  for (auto &next : g[node].adj) {
    DfsForward(g, next.to, visited, stk);
  }

  // when all of a node's descendents are exhausted, add it to the stack
  stk.push(node);
}

void DfsBackward(const std::vector<dsa::graph::Node> &g, int node,
                 std::vector<bool> &visited, std::vector<int> &scc) {
  // Don't revisit nodes.
  if (!visited[node]) {
    return;
  }
  visited[node] = false;

  // Recurse through reachable nodes.
  for (auto &next : g[node].adj) {
    DfsBackward(g, next.to, visited, scc);
  }

  // Add the node to the current strongly connected component.
  // (This can happen before processing descendents.)
  scc.push_back(node);
}

} // namespace

namespace dsa::scc {

std::vector<std::vector<int>> Kosaraju(const graph::Graph &g) {
  std::stack<int> stk{};
  std::vector<bool> visited(g.nodes_.size(), false);
  std::vector<std::vector<int>> sccs{};
  std::vector<int> scc{};

  // Perform initial dfs
  DfsForward(g.nodes_, 0, visited, stk);

  // Perform dfs on reversed graph
  graph::Graph g2{g.Transpose()};

  while (!stk.empty()) {
    auto node{stk.top()};
    stk.pop();

    // Ignore nodes that are already found to be in a
    // strongly-connected component.
    if (visited[node]) {
      scc.clear();
      DfsBackward(g2.nodes_, node, visited, scc);
      sccs.push_back(scc);
    }
  }

  return sccs;
}

} // namespace dsa::scc
