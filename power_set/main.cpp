#include "./power_set.hpp"

// lc_0078

int main() {
        vi v1{1,2,3}, v2{0};
        vvi res1{{},{3},{2},{2,3},{1},{1,3},{1,2},{1,2,3}},
                res2{{},{0}};

        assert(subsets(v1) == res1);
        assert(subsets(v2) == res2);

        cout << "Done." << endl;
        return 0;
}
