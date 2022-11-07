#include "binary_search.hpp"

#include <vector>

#include "../utils/common.hpp"

using dsa::binary_search::BinarySearch;
using dsa::binary_search::FindRotation;

int main() {
  std::vector<int> v1{8, 9, 1, 2, 3, 4, 5, 6, 7}, v2{1, 2, 3, 4, 5, 6, 7, 8, 9};

  assert_eq(BinarySearch(v2, 6).value(), 5);
  assert_eq(BinarySearch(v2, 2).value(), 1);
  assert(!BinarySearch(v2, 32));

  assert_eq(FindRotation(v1), 2);
  assert_eq(FindRotation(v2), 0);

  return 0;
}
