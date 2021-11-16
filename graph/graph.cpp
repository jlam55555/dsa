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

graph graph::transpose() {
        vector<edge> new_edges{};

        // reverse all edges
        for (auto n : nodes) {
                for (auto e : n.adj) {
                        new_edges.push_back({e.to, e.from, e.weight});
                }
        }
        
        return graph{new_edges};
}

void graph::print() {
        cout << "graph &" << this << endl;
        for (int i = 0; i < nodes.size(); ++i) {
                cout << i << ": ";
                for (auto e : nodes[i].adj) {
                        cout << e.to << ":" << e.weight << " ";
                }
                cout << endl;
        }
        cout << endl;
}
