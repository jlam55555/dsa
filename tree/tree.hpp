#ifndef DSA_TREE_HPP
#define DSA_TREE_HPP

#include "../utils/common.hpp"

// compatible with Leetcode's TreeNode
struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x = 0, TreeNode *left = nullptr, TreeNode *right = nullptr);

        // tree equality
        static bool equals(TreeNode *t1, TreeNode *t2);

        // serialization/deserialization (leetcode 297)
        static TreeNode *from(string data);
        static string to_string(TreeNode *root);
};

// helper similar to assert_eq
#define assert_tree_eq(t1, t2) assert(TreeNode::equals(t1, t2))

#endif
