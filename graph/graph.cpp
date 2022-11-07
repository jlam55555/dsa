#include <iostream>
#include <optional>
#include <queue>
#include <vector>

#include "graph.hpp"

namespace dsa::graph {

Graph::Graph(const std::vector<Edge> &edges, bool directed)
    : directed_{directed} {
  // Compute the size of the nodes vector so we don't have to
  // repeatedly do memory allocation for the `nodes_` array.
  // Tradeoff of doing two passes to avoid allocation cost.
  auto max_node{0u};
  for (auto &e : edges) {
    max_node = std::max(max_node, std::max(e.from, e.to));
  }
  nodes_ = std::vector<Node>(max_node + 1);

  // Fill nodes array.
  for (auto &e : edges) {
    nodes_[e.from].adj.push_back(e);
    ++nodes_[e.to].indegree;
    if (!directed_) {
      nodes_[e.to].adj.push_back(Edge{e.to, e.from, e.weight});
      ++nodes_[e.from].indegree;
    }
  }
}

unsigned Graph::Size() const { return nodes_.size(); }

Graph Graph::Transpose() const {
  if (!directed_) {
    // Return a copy of this graph.
    return *this;
  }

  // Reverse all edges.
  std::vector<Edge> new_edges{};
  for (auto &n : nodes_) {
    for (auto &e : n.adj) {
      new_edges.push_back(Edge{e.to, e.from, e.weight});
    }
  }

  return Graph{new_edges};
}

void Graph::Print() const {
  std::cout << "graph &" << this << std::endl;
  for (auto i{0}; i < nodes_.size(); ++i) {
    std::cout << i << ": ";
    for (auto &e : nodes_[i].adj) {
      std::cout << e.to << ":" << e.weight << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

} // namespace dsa::graph
