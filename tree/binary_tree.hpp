#ifndef DSA_TREE_BINARY_TREE_HPP
#define DSA_TREE_BINARY_TREE_HPP

#include <string>
#include <string_view>

#include "../utils/common.hpp"

namespace dsa::tree {

// Binary tree node. Equivalent to Leetcode's `TreeNode`.
struct BinaryTreeNode {
  int val{0};
  BinaryTreeNode *left{nullptr};
  BinaryTreeNode *right{nullptr};

  // Tree equality
  bool operator=(const BinaryTreeNode &) const;

  // Tree equality (for pointers). This is safer than the above, since
  // we usually have BinaryTreeNode pointers and we don't want to dereference
  // them in case the tree is empty.
  static bool Equals(const BinaryTreeNode *, const BinaryTreeNode *);

  // Serialization/deserialization (leetcode 297).
  static BinaryTreeNode *From(const std::string_view);
  std::string ToString(const BinaryTreeNode *) const;
};

} // namespace dsa::tree

// Helper similar to assert_eq.
// Define out of the namespace akin to `assert()` and `assert_eq()`.
void assert_tree_eq(const dsa::tree::BinaryTreeNode *,
                    const dsa::tree::BinaryTreeNode *);

#endif // DSA_TREE_BINARY_TREE_HPP
