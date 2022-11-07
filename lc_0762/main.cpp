#include <unordered_set>

#include "set_bits/set_bits.hpp"
#include "utils/common.hpp"

std::unordered_set<int> primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

int CountPrimeSetBits(int left, int right) {
  auto count{0};
  for (auto i{left}; i <= right; ++i) {
    count += primes.count(dsa::set_bits::CountSetBits(i));
  }
  return count;
}

int main(void) {
  assert_eq(CountPrimeSetBits(6, 10), 4);
  assert_eq(CountPrimeSetBits(10, 15), 5);

  return 0;
}
