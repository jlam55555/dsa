#include "graph.hpp"

graph::graph(::vector<edge> edges, bool directed) : directed{directed} {
        int max_node = 0;

        for (auto e : edges) {
                max_node = ::max(max_node, max(e.from, e.to));
        }

        nodes = vector<node>(max_node+1);

        for (auto e : edges) {
                nodes[e.from].adj.push_back(e);
                if (!directed) {
                        nodes[e.to].adj.push_back({e.to, e.from, e.weight});
                }
        }
}

int graph::size(void) {
        return nodes.size();
}
