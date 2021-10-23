#ifndef DSA_MD_ARRAY_HPP
#define DSA_MD_ARRAY_HPP

#include <cstddef>
void **alloc_2d(int m, int n, ::size_t size, bool zero=false);
void free_2d(void** dp, int m);

#endif
