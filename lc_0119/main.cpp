#include <vector>

#include "../utils/common.hpp"

// This version is very terse and definitely doesn't follow the style guide.
// Don't write code like this. This is kind of a fun mess to decipher though,
// so I'll leave it as is.
std::vector<int> GetRow(int ri) {
  int rs[2][ri + 1], r, i, j;
  for (r = i = 0, rs[0][0] = 1; i < ri;
       rs[!r][0] = rs[!r][i + 1] = 1, ++i, r ^= 1)
    for (j = 1; j <= i; rs[!r][j] = rs[r][j - 1] + rs[r][j], ++j)
      ;
  return std::vector(rs[r], rs[r] + ri + 1);
}

int main() {
  std::vector<int> res1{1, 3, 3, 1}, res2{1}, res3{1, 1};

  assert_eq(GetRow(3), res1);
  assert_eq(GetRow(0), res2);
  assert_eq(GetRow(1), res3);

  return 0;
}
