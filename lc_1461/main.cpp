#include <bitset>
#include <string_view>

#include "../utils/common.hpp"

// Note: 1<=k<=20, 1<=s.length()<=5e5
bool HasAllCodes(const std::string_view s, int k) {
  // We're looking for 2^k elements
  // 1 <= k <= 20
  // 2^20 = 1048576
  // 2^19 = 524288
  // 2^18 = 262144
  // 2^20 and 2^19 aren't even possible given the constraints
  // given a string of length l, number of substrings of length k is l-k+1
  unsigned cnt{1u << k};
  if (s.length() - k + 1 < cnt) {
    return false;
  }

  std::bitset<262144> seen{};
  unsigned i{0}, val{0};
  for (; i < k && i < s.length(); ++i) {
    val = (val << 1) | (s[i] - '0');
  }
  seen.set(val);

  for (; i < s.length(); ++i) {
    val = ((val << 1) | (s[i] - '0')) & ~cnt;
    seen.set(val);
  }

  return seen.count() == cnt;
}

int main() {
  assert(HasAllCodes("00110110", 2));
  assert(HasAllCodes("00110", 2));
  assert(HasAllCodes("0110", 1));
  assert(!HasAllCodes("0110", 2));
  assert(!HasAllCodes("0000000001011100", 4));
  assert(!HasAllCodes("0101", 13));

  return 0;
}
