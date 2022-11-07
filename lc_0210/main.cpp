#include <vector>

#include "../graph/graph.hpp"
#include "../utils/common.hpp"

// This is a topological sort problem.
std::vector<dsa::graph::NodeIndex>
findOrder(int num_courses, std::vector<std::vector<int>> &prerequisites) {
  // Convert prerequisites vector into a vector of `Edge`s.
  std::vector<dsa::graph::Edge> edges{};
  edges.reserve(prerequisites.size());
  for (auto &edge : prerequisites) {
    edges.push_back(
        dsa::graph::Edge{static_cast<dsa::graph::NodeIndex>(edge[1]),
                         static_cast<dsa::graph::NodeIndex>(edge[0])});
  }

  // Perform topological sort.
  const auto top_sort{dsa::graph::TopologicalSort(dsa::graph::Graph{edges})};
  return top_sort.size() < num_courses ? std::vector<dsa::graph::NodeIndex>{}
                                       : top_sort;
}

int main() {
  std::vector<std::vector<int>> v1{{1, 0}}, v2{{1, 0}, {2, 0}, {3, 1}, {3, 2}},
      v3{};

  std::vector<dsa::graph::NodeIndex> a1{0, 1}, a2{0, 1, 2, 3}, a3{0};

  assert(findOrder(2, v1) == a1);
  assert(findOrder(4, v2) == a2);
  assert(findOrder(1, v3) == a3);

  return 0;
}
