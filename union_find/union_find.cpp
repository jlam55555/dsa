#include "utils/common.hpp"
#include "../union_find/union_find.hpp"

unionfind::unionfind(int size) : arr{vector<int>(arr)} {
        int i;

        // initialize all elements to singleton set
        for (i = 0; i < size; ++i) {
                arr[i] = i;
        }
}

int unionfind::find(int e) {
        // TODO: working here
        return -1;
}

int unionfind::unio(int e1, int e2) {
        // TODO: working here
        return -1;
}

int unionfind::size(void) {
        return arr.size();
}

int unionfind::groups(void) {
        return groupCount;
}
