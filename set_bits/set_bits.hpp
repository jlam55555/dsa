#ifndef DSA_SET_BITS_SET_BITS_HPP
#define DSA_SET_BITS_SET_BITS_HPP

namespace dsa::set_bits {

// Count the number of set bits in a word.
// A.k.a. Kernighan's algorithm.
unsigned CountSetBits(unsigned n);

} // namespace dsa::set_bits

#endif // DSA_SET_BITS_SET_BITS_HPP
