#ifndef DSA_MST_MST_HPP
#define DSA_MST_MST_HPP

#include <vector>

#include "../graph/graph.hpp"
#include "../utils/common.hpp"

namespace dsa::mst {

// Performs Kruskal's algorithm for finding a minimum spanning tree.
// Note: modifies `edges`.
int Kruskal(std::vector<graph::Edge> &edges);

} // namespace dsa::mst

#endif // DSA_MST_MST_HPP
