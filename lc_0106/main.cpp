#include <vector>

#include "../tree/binary_tree.hpp"
#include "../utils/common.hpp"

using dsa::tree::BinaryTreeNode;

// Create a tree from `inorder[li:ri]`, `postorder[lp:rp]`.
BinaryTreeNode *BuildTreeRec(const std::vector<int> &inorder, int li, int ri,
                             const std::vector<int> &postorder, int lp,
                             int rp) {
  // Empty tree
  if (li == ri) {
    return nullptr;
  }

  // Get parent
  auto parent{postorder[rp - 1]};

  // Get pivot between left and right
  auto pivot{li}, len{0};
  for (; pivot < ri; ++pivot, ++len) {
    if (inorder[pivot] == parent) {
      break;
    }
  }

  // recursively build tree
  return new BinaryTreeNode{
      parent, BuildTreeRec(inorder, li, li + len, postorder, lp, lp + len),
      BuildTreeRec(inorder, li + len + 1, ri, postorder, lp + len, rp - 1)};
}

BinaryTreeNode *BuildTree(const std::vector<int> &inorder,
                          const std::vector<int> &postorder) {
  // Inorder: left, parent, right
  // Postorder: left, right, parent
  auto n{inorder.size()};
  return BuildTreeRec(inorder, 0, n, postorder, 0, n);
}

int main() {
  assert_tree_eq(BuildTree({9, 3, 15, 20, 7}, {9, 15, 7, 20, 3}),
                 BinaryTreeNode::From("[3,9,20,null,null,15,7]"));
  assert_tree_eq(BuildTree({-1}, {-1}), BinaryTreeNode::From("[-1]"));

  return 0;
}
