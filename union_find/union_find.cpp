#include "union_find.hpp"

// haskell-style indenting? not sure if this is blasphemy
union_find::union_find(int size)
        : arr{::vector<int>(size)}
        , group_sizes{::vector<int>(size, 1)}
        , group_count{size}
{
        int i;

        // initialize all elements to singleton set
        for (i = 0; i < size; ++i) {
                arr[i] = i;
        }
}

int union_find::find(int e) {
        int root = e, tmp;

        if (e < 0 || e >= size()) {
                throw ::invalid_argument{"element out of bounds"};
        }
        
        while (arr[root] != root) {
                root = arr[root];
        }

        // path compression
        while (arr[e] != root) {
                tmp = arr[e];
                arr[e] = root;
                e = tmp;
        }
        
        return root;
}

bool union_find::unio(int e1, int e2) {
        int g1 = find(e1), g2 = find(e2), new_size;
        
        if (g1 == g2) {
                // no union
                return false;
        }

        new_size = group_sizes[g1] + group_sizes[g2];
        --group_count;
        
        if (group_sizes[g1] < group_sizes[g2]) {
                arr[g1] = g2;
                group_sizes[g2] = new_size;
        } else {
                arr[g2] = g1;
                group_sizes[g1] = new_size;
        }

        return true;
}

int union_find::size(void) {
        return arr.size();
}

int union_find::groups(void) {
        return group_count;
}
