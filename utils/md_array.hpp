#ifndef DSA_UTILS_MD_ARRAY_HPP
#define DSA_UTILS_MD_ARRAY_HPP

#include <cstddef>

namespace dsa::utils {

// Allocate a 2-D array (array of arrays). Note that this is not
// contiguous.
void **Alloc2D(int m, int n, std::size_t elem_size, bool zero = false);

// Free a 2-D array created by `Alloc2D`.
void Free2D(void **dp, int m);

} // namespace dsa::utils

#endif // DSA_UTILS_MD_ARRAY_HPP
