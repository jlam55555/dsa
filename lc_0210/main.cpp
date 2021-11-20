#include "../utils/common.hpp"

// topological sort time
// for each pair [p,q] p is an incoming edge to q
    
struct node {
        int indegree{};
        vector<int> adj{};
};
    
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<node> g(numCourses, {0});
        queue<int> indegree0{};
        
        for (const auto &pq : prerequisites) {
                g[pq[1]].adj.push_back(pq[0]);
                ++g[pq[0]].indegree;
        }
        
        for (int i = 0; i < numCourses; ++i) {
                if (!g[i].indegree) {
                        indegree0.push(i);
                }
        }
        
        vector<int> res{};
        
        while (!indegree0.empty()) {
                auto n = indegree0.front();
                indegree0.pop();
                        
                res.push_back(n);
            
                for (auto n2 : g[n].adj) {
                        if (--g[n2].indegree == 0) {
                                indegree0.push(n2);
                        }
                }
        }
        
        if (res.size() != numCourses)
                return {};
        
        return res;
}

int main() {
        vvi v1{{1,0}},
                v2{{1,0},{2,0},{3,1},{3,2}},
                v3{};

        vi a1{0,1},
                a2{0,1,2,3},
                a3{0};

        assert(findOrder(2, v1) == a1);
        assert(findOrder(4, v2) == a2);
        assert(findOrder(1, v3) == a3);
        
        DONE;
}
