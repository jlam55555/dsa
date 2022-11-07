#ifndef DSA_FIB_FIB_HPP
#define DSA_FIB_FIB_HPP

#include <cstdint>

namespace dsa::fib {

// Compute the `n`-th Fibonacci number.
// The (0-indexed) sequence begins with
// 0, 1, 1, 2, 3, 5, 8, 13, ...
constexpr uint64_t Fibonacci(unsigned n);

} // namespace dsa::fib

#endif // DSA_FIB_FIB_HPP
