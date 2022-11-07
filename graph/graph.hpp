#ifndef DSA_GRAPH_GRAPH_HPP
#define DSA_GRAPH_GRAPH_HPP

#include <optional>
#include <vector>

#include "../utils/common.hpp"

namespace dsa {

// Forward declarations for friend declarations.
namespace graph {
class Graph;
} // namespace graph

namespace scc {
std::vector<std::vector<int>> Kosaraju(const graph::Graph &);
} // namespace scc

namespace graph {

// For type-safer representation of node indices.
using NodeIndex = unsigned;

// A directed, weighted edge (think Dijkstra's).
// Note that we also represented undirected graphs using
// directed edges (each edge has a corresponding reversed edge).
struct Edge {
  // We probably don't need to store `from` in the
  // edge, but we'll leave it for now.
  NodeIndex from;
  NodeIndex to;

  // Edges may not have a weight. Set it to a default of 0.
  int weight{0};

  // Custom comparator functor for sort.
  bool operator()(const Edge &e1, const Edge &e2) const {
    return e1.weight < e2.weight;
  }

  // Comparator for default sort.
  bool operator<(const Edge &e) const { return weight < e.weight; }

  // Transpose edge.
  Edge Transpose() const { return Edge{to, from, weight}; }
};

// Adjacency-list representation of a graph node.
struct Node {
  // Value (if any).
  int val;

  // Adjacency list (outgoing edges).
  std::vector<Edge> adj;

  // May not need to store indegree. This is primarily for
  // topological sort. It is currently only modified and maintained
  // by `Graph::Graph()` and `Graph::TopologicalSort()`. Any other
  // (non-const) methods are not guaranteed to maintain the indegree.
  unsigned indegree{0};
};

// Adjacency list representation of a graph.
class Graph {
public:
  // Construct a Graph from a collection of directed edges.
  Graph(const std::vector<Edge> &edges, bool directed = true);

  // Return the number of nodes in the graph.
  unsigned Size() const;

  // Transpose all edges.
  Graph Transpose() const;

  // Returns the minimum weighted path from node `from` to node `to`.
  // Precondition: All edges have nonnegative weights.
  //
  // This mutates the node values.
  //
  // Returns `std::nullopt` if `from` and `to` are not connected.
  std::optional<unsigned> Dijkstra(NodeIndex from, NodeIndex to);

  // Print adjacency lists.
  void Print() const;

private:
  std::vector<Node> nodes_;
  bool directed_;

  // Friend methods below for graph algorithms, so that they can access
  // private members of the graphs. If they are destructive, then they will
  // take `Graph` as an rvalue-reference.
  friend std::optional<unsigned> Dijkstra(const Graph &, NodeIndex from,
                                          NodeIndex to);
  friend std::vector<NodeIndex> TopologicalSort(Graph &&);
  friend std::vector<std::vector<int>> scc::Kosaraju(const graph::Graph &);
};

// Dijkstra's algorithm for finding the shortest weighted path between
// two nodes on a directed graph with no nonnegative edge weights.
std::optional<unsigned> Dijkstra(const Graph &, NodeIndex from, NodeIndex to);

// Return any valid topological sort of the nodes. If there is a cycle,
// return an empty array. This mutates the graph.
std::vector<NodeIndex> TopologicalSort(Graph &&);

} // namespace graph
} // namespace dsa

#endif // DSA_GRAPH_GRAPH_HPP
