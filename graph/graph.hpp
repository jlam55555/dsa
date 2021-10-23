#ifndef DSA_GRAPH_HPP
#define DSA_GRAPH_HPP

#include "../utils/common.hpp"

// adj list representation of graph
class graph {
public:
        struct edge {
                int from, to, weight;

                // for use in custom sort
                bool operator()(const edge& e1, const edge& e2) {
                        return e1.weight < e2.weight;
                }

                // for use in ordinary comparisons/regular sort
                bool operator<(const edge& e) {
                        return weight < e.weight;
                }
        };
        struct node {
                int val;
                ::vector<edge> adj;
        };

        // to make some algorithms easier (e.g., kruskal) without
        // extending the `graph` class, leave these public access
        ::vector<node> nodes;
        bool directed;

        graph(::vector<edge> edges, bool directed = true);
        int size(void);
};

#endif
