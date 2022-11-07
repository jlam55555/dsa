#ifndef DSA_SCC_SCC_HPP
#define DSA_SCC_SCC_HPP

#include <vector>

#include "../graph/graph.hpp"

namespace dsa::scc {

// Compute the strongly-connected components of a graph.
std::vector<std::vector<int>> Kosaraju(const graph::Graph &g);

} // namespace dsa::scc

#endif // DSA_KOSARAJU_KOSARAJU_HPP
