#include "../graph/graph.hpp"

static void dfs_forward(graph &g, int node, vector<bool> &visited, stack<int> &stk) {
        // don't revisit nodes
        if (visited[node]) {
                return;
        }
        visited[node] = true;

        // recurse through descendants
        for (auto next : g.nodes[node].adj) {
                dfs_forward(g, next.to, visited, stk);
        }

        // when all of a node's descendents are exhausted, add it to the stack
        stk.push(node);
}

static void dfs_backward(graph &g, int node, vector<bool> &visited, vector<int> &scc) {
        // don't revisit nodes
        if (!visited[node]) {
                return;
        }
        visited[node] = false;

        // recurse through reachable nodes
        for (auto next : g.nodes[node].adj) {
                dfs_backward(g, next.to, visited, scc);
        }

        // add the node to the current scc (this can happen before processing desc.)
        scc.push_back(node);
}

vector<vector<int>> kosaraju(graph &g) {
        stack<int> stk{};
        vector<bool> visited(g.nodes.size(), false);
        vector<vector<int>> sccs{};
        vector<int> scc{};

        // perform initial dfs
        dfs_forward(g, 0, visited, stk);

        // perform dfs on reversed graph
        graph g2 = g.transpose();

        while (!stk.empty()) {
                int node = stk.top();
                stk.pop();

                // ignore nodes that are already found to be in a scc
                if (visited[node]) {
                        scc.clear();
                        dfs_backward(g2, node, visited, scc);
                        sccs.push_back(scc);
                }
        }

        return sccs;
}
