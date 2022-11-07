#include "./binary_tree.hpp"

#include <queue>
#include <string>
#include <string_view>
#include <vector>

#include "../utils/string.hpp"

namespace dsa::tree {

bool BinaryTreeNode::operator=(const BinaryTreeNode &t) const {
  if (val != t.val) {
    return false;
  }

  return BinaryTreeNode::Equals(left, t.left) &&
         BinaryTreeNode::Equals(right, t.right);
}

bool BinaryTreeNode::Equals(const BinaryTreeNode *t1,
                            const BinaryTreeNode *t2) {
  if (!t1 && !t2) {
    return true;
  }

  if (!t1 || !t2 || t1->val != t2->val) {
    return false;
  }

  return BinaryTreeNode::Equals(t1->left, t2->left) &&
         BinaryTreeNode::Equals(t1->right, t2->right);
}

BinaryTreeNode *BinaryTreeNode::From(const std::string_view data) {
  const auto data_no_brackets{data.substr(1, data.length() - 2)};
  std::vector<std::string> cells{
      dsa::utils::StringSplit(data_no_brackets, ',')};

  if (cells.size() == 1 && cells[0] == "") {
    return nullptr;
  }

  std::vector<BinaryTreeNode *> cur_row{}, next_row{};
  auto j{1};

  cur_row.push_back(new BinaryTreeNode{std::stoi(cells[0]), nullptr, nullptr});
  const auto root{cur_row[0]};

  while (j < cells.size()) {
    for (auto i{0}; j < cells.size() && i < 2 * cur_row.size(); ++i, ++j) {
      if (cells[j] != "null") {
        auto newNode{new BinaryTreeNode{std::stoi(cells[j]), nullptr, nullptr}};
        next_row.push_back(newNode);
        if (i % 2 == 0) {
          cur_row[i / 2]->left = newNode;
        } else {
          cur_row[i / 2]->right = newNode;
        }
      }
    }
    std::swap(cur_row, next_row);
    next_row = {};
  }

  return root;
}

std::string BinaryTreeNode::ToString(const BinaryTreeNode *root) const {
  if (!root) {
    return "[]";
  }

  std::string res = "[";

  std::queue<const BinaryTreeNode *> q{};
  q.push(root);
  auto found{0}, prev_found{-1};
  while (found >= 0) {
    prev_found = found;
    found = -1;
    auto s{q.size()};
    for (auto i{0}; i <= s && !q.empty(); ++i) {
      auto t = q.front();
      q.pop();

      if (!t) {
        res += "null,";
        continue;
      }

      res += std::to_string(t->val) + ",";
      if (t->left) {
        found = 2 * i;
      }
      if (t->right) {
        found = 2 * i + 1;
      }
      q.push(t->left);
      q.push(t->right);
    }
  }

  return res.substr(0, res.length() - 1) + "]";
}

} // namespace dsa::tree

void assert_tree_eq(const dsa::tree::BinaryTreeNode *t1,
                    const dsa::tree::BinaryTreeNode *t2) {
  assert(dsa::tree::BinaryTreeNode::Equals(t1, t2));
}
