#include "union_find.hpp"

#include <stdexcept>
#include <vector>

namespace dsa::union_find {

DisjointSet::DisjointSet(unsigned size)
    : arr_(size), group_sizes_(size, 1u), group_count_{size} {
  // Initialize all elements to singleton set.
  for (auto i{0}; i < size; ++i) {
    arr_[i] = i;
  }
}

unsigned DisjointSet::Find(unsigned e) {
  auto root{e};

  if (e < 0 || e >= Size()) {
    // TODO: Remove exception to be compliant with the style guide.
    throw std::invalid_argument{"element out of bounds"};
  }

  while (arr_[root] != root) {
    root = arr_[root];
  }

  // Path compression.
  while (arr_[e] != root) {
    auto tmp = arr_[e];
    arr_[e] = root;
    e = tmp;
  }

  return root;
}

bool DisjointSet::Union(unsigned e1, unsigned e2) {
  const auto g1{Find(e1)}, g2{Find(e2)};

  if (g1 == g2) {
    // No union.
    return false;
  }

  auto new_size = group_sizes_[g1] + group_sizes_[g2];
  --group_count_;

  if (group_sizes_[g1] < group_sizes_[g2]) {
    arr_[g1] = g2;
    group_sizes_[g2] = new_size;
  } else {
    arr_[g2] = g1;
    group_sizes_[g1] = new_size;
  }

  return true;
}

} // namespace dsa::union_find
