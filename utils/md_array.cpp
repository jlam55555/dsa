#include <cstdlib>
#include <cstring>
#include "md_array.hpp"

void **alloc_2d(int m, int n, ::size_t size, bool zero) {
        int i, j;
        void **arr;

        arr = (void **) ::malloc(m * sizeof(void *));
        for (i = 0; i < m; ++i) {
                arr[i] = ::malloc(n * size);

                if (zero) {
                        ::memset(arr[i], 0, n*size);
                }
        }

        return arr;
}

void free_2d(void** dp, int m) {
        int i;
        
        for (i = 0; i < m; ++i) {
                free(dp[i]);
        }
        free(dp);
}
