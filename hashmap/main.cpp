#include "./hashmap.hpp"

// a.k.a. lc_0706: design a hashmap
int main() {
        hashmap hm{};
        
        hm.put(1, 1);
        hm.put(2, 2);
        assert(hm.get(1) == 1);
        assert(hm.get(3) == -1);
        hm.put(2, 1);
        assert(hm.get(2) == 1);
        hm.remove(2);
        assert(hm.get(2) == -1);

        cout << "Done." << endl;
        return 0;
}
