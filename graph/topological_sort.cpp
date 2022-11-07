#include <queue>
#include <vector>

#include "graph.hpp"

namespace dsa::graph {

std::vector<NodeIndex> TopologicalSort(Graph &&g) {
  std::queue<NodeIndex> indegree_zero{};

  for (auto i{0}; i < g.nodes_.size(); ++i) {
    if (!g.nodes_[i].indegree) {
      indegree_zero.push(i);
    }
  }

  std::vector<NodeIndex> res{};
  while (!indegree_zero.empty()) {
    auto i{indegree_zero.front()};
    indegree_zero.pop();
    res.push_back(i);

    for (const auto &edge : g.nodes_[i].adj) {
      if (!--g.nodes_[edge.to].indegree) {
        indegree_zero.push(edge.to);
      }
    }
  }

  // We have a cycle. No valid topological sort.
  if (res.size() != g.nodes_.size())
    return {};

  return res;
}

} // namespace dsa::graph
