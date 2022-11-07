#include <bitset>
#include <string>
#include <vector>

#include "../set_bits/set_bits.hpp"
#include "../utils/common.hpp"

int MaxLength(const std::vector<std::string> &arr) {
  // Unique concatenations.
  std::vector<std::bitset<26>> ucs{0};
  auto max_len{0};

  for (const auto &s : arr) {
    // Gather std::bitset for the current std::string
    std::bitset<26> bm1{0};
    for (char c : s) {
      // repeated characters, skip this std::string
      if (bm1[c - 'a']) {
        goto cont;
      }
      bm1.set(c - 'a');
    }

    // add any permutations that work
    for (auto i{int(ucs.size()) - 1}; i >= 0; --i) {
      std::bitset<26> bm2{ucs[i]};
      if (!(bm1 & bm2).any()) {
        ucs.push_back(bm1 | bm2);
        max_len = std::max(max_len, int((bm1 | bm2).count()));
      }
    }

  cont:;
  }

  return max_len;
}

// same as the above, but using ints rather than bitstd::strings
int bits[26]{
    0x00000001, 0x00000002, 0x00000004, 0x00000008, 0x00000010, 0x00000020,
    0x00000040, 0x00000080, 0x00000100, 0x00000200, 0x00000400, 0x00000800,
    0x00001000, 0x00002000, 0x00004000, 0x00008000, 0x00010000, 0x00020000,
    0x00040000, 0x00080000, 0x00100000, 0x00200000, 0x00400000, 0x00800000,
    0x01000000, 0x02000000,
};
int MaxLengthInt(const std::vector<std::string> &arr) {
  std::vector<int> ucs{0};
  auto max_len{0};

  for (const auto &s : arr) {
    auto bm1{0};
    for (auto c : s) {
      if (bm1 & bits[c - 'a']) {
        goto cont;
      }
      bm1 |= bits[c - 'a'];
    }

    for (auto i{int(ucs.size()) - 1}; i >= 0; --i) {
      auto bm2{ucs[i]};
      if (!(bm1 & bm2)) {
        ucs.push_back(bm1 | bm2);
        max_len =
            std::max(max_len, int(dsa::set_bits::CountSetBits(bm1 | bm2)));
      }
    }

  cont:;
  }

  return max_len;
}

int main(void) {
  const std::vector<std::string> v1{"un", "iq", "ue"},
      v2{"cha", "r", "act", "ers"}, v3{"abcdefghijklmnopqrstuvwxyz"},
      v4{"aa", "bb"};

  assert_eq(MaxLength(v1), 4);
  assert_eq(MaxLength(v2), 6);
  assert_eq(MaxLength(v3), 26);
  assert_eq(MaxLength(v4), 0);

  assert_eq(MaxLengthInt(v1), 4);
  assert_eq(MaxLengthInt(v2), 6);
  assert_eq(MaxLengthInt(v3), 26);
  assert_eq(MaxLengthInt(v4), 0);

  return 0;
}
