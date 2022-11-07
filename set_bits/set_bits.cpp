#include "set_bits.hpp"

namespace dsa::set_bits {

unsigned CountSetBits(unsigned n) {
  unsigned count{0};

  while (n) {
    n &= n - 1;
    ++count;
  }

  return count;
}

} // namespace dsa::set_bits
