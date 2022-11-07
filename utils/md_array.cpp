#include "md_array.hpp"

#include <cstdlib>
#include <cstring>

namespace dsa::utils {

void **Alloc2D(int m, int n, std::size_t elem_size, bool zero) {
  auto arr = static_cast<void **>(std::malloc(m * sizeof(void *)));
  for (auto i = 0; i < m; ++i) {
    arr[i] = std::malloc(n * elem_size);
    if (zero) {
      std::memset(arr[i], 0, n * elem_size);
    }
  }
  return arr;
}

void Free2D(void **dp, int m) {
  for (auto i = 0; i < m; ++i) {
    std::free(dp[i]);
  }
  std::free(dp);
}

} // namespace dsa::utils
