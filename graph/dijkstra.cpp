#include <climits>
#include <queue>
#include <vector>

#include "graph.hpp"

namespace {

// Utility class for Dijkstra's algorithm. This extends each node in
// the graph's `nodes_` vector with Dijkstra-specific state.
struct DijkstraNode {
  // Reference to the adjacency list of the node from the
  // `Graph::Node` in the graph's `nodes_` vector.
  const std::vector<dsa::graph::Edge> &adj;

  // Minimum path sum to this node. Initially set to the maximum,
  // except for the root node.
  unsigned shortest_path{UINT_MAX};

  // Whether this node has been visited before.
  bool seen{false};

  // Custom comparator, so that we can find the minimum-weight node.
  // This is reversed because `std::priority_queue` tries to find the
  // largest element by default.
  struct Compare {
    bool operator()(DijkstraNode *&n1, DijkstraNode *&n2) const {
      return n1->shortest_path > n2->shortest_path;
    }
  };
};

} // namespace

namespace dsa::graph {

std::optional<unsigned> Dijkstra(const Graph &g, NodeIndex from, NodeIndex to) {
  assert(from < g.Size());
  assert(to < g.Size());

  // Keep track of data needed for Dijkstra's algorithm in `nodes` rather
  // than in `g.nodes_`. This allows us to keep `g` const. Otherwise we can
  // store these values directly in the nodes.
  //
  // We do it this way to avoid the overhead for other graph algorithms that
  // do not require this extra capability.
  std::vector<DijkstraNode> nodes;
  nodes.reserve(g.Size());
  for (const auto &node : g.nodes_) {
    nodes.emplace_back(DijkstraNode{node.adj});
  }

  // Create priority queue, sorted by minimum weight.
  std::priority_queue<DijkstraNode *, std::vector<DijkstraNode *>,
                      DijkstraNode::Compare>
      pq;

  // Add root node to priority queue.
  nodes[from].shortest_path = 0;
  pq.push(&nodes[from]);

  // Loop through nodes, choosing greedily by minimum weight, until we
  // reach the target end node.
  while (!pq.empty()) {
    auto node{pq.top()};
    pq.pop();

    // If we've seen this node before, continue.
    if (node->seen) {
      continue;
    }
    node->seen = true;

    // If this is the target end node, we're done. Using pointer comparison
    // here to check if the index is correct.
    if (node == &nodes[to]) {
      return node->shortest_path;
    }

    // Process neighbors. Add them to the `pq` if we find a new minimum
    // path sum to them.
    for (const auto &e : node->adj) {
      const auto &new_path{node->shortest_path + e.weight};
      if (new_path < nodes[e.to].shortest_path) {
        nodes[e.to].shortest_path = new_path;
        pq.push(&nodes[e.to]);
      }
    }
  }

  // `from` and `to` nodes are not connected.
  return {};
}

} // namespace dsa::graph
