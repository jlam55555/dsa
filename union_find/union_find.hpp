#ifndef DSA_UNION_FIND_UNION_FIND_HPP
#define DSA_UNION_FIND_UNION_FIND_HPP

#include <vector>

namespace dsa::union_find {

// This is the disjoint-set data structure, which implements
// the efficient union/find operations.
class DisjointSet {
public:
  DisjointSet(unsigned size);

  // Find which disjoint set `e` is in.
  // Note: Find() is not const due to path compression.
  unsigned Find(unsigned e);

  // Join two disjoint sets.
  bool Union(unsigned e1, unsigned e2);

  // Return the total number of elements.
  unsigned Size() const { return arr_.size(); }

  // Return the number of disjoint sets.
  unsigned Groups() const { return group_count_; }

private:
  // Number of disjoint sets.
  unsigned group_count_;

  // Backing store for elements.
  std::vector<unsigned> arr_;

  // Size of each disjoint set.
  std::vector<unsigned> group_sizes_;
};

} // namespace dsa::union_find

#endif // DSA_UNION_FIND_UNION_FIND_HPP
