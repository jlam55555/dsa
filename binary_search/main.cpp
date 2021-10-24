#include "../utils/common.hpp"
#include "binary_search.hpp"

int main(void) {
        vector<int>
                v1{8,9,1,2,3,4,5,6,7},
                v2{1,2,3,4,5,6,7,8,9};

        assert(binary_search(v2, 6) == 5);
        assert(binary_search(v2, 2) == 1);
        assert(binary_search(v2, 32) == -1);

        assert(find_rotation(v1) == 2);
        assert(find_rotation(v2) == 0);

        cout << "Done." << endl;
        return 0;
}
