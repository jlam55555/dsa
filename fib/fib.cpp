#include <cstdint>

#include "fib.hpp"

namespace dsa::fib {

constexpr uint64_t Fibonacci(unsigned n) {
  uint64_t a{0}, b{1}, tmp{0};
  if (n < 2) {
    return n;
  }
  while (--n) {
    tmp = b;
    b += a;
    a = tmp;
  }
  return b;
}

} // namespace dsa::fib
