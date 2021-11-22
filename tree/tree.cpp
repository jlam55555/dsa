#include "./tree.hpp"
#include "../utils/string.hpp"

TreeNode::TreeNode(int x, TreeNode *left, TreeNode *right)
        : val{x}, left{left}, right{right} {}

bool TreeNode::equals(TreeNode *t1, TreeNode *t2) {
        if (!t1 && !t2) {
                return true;
        }

        if (!t1 || !t2 || t1->val != t2->val) {
                return false;
        }

        return TreeNode::equals(t1->left, t2->left)
                && TreeNode::equals(t1->right, t2->right);
}

TreeNode *TreeNode::from(string data) {
        int i = 0;
        string data_no_brackets = data.substr(1,data.length()-2);
        vector<string> cells = string_split(data_no_brackets, ',');
        
        if (cells.size() == 1 && cells[0] == "") {
                return nullptr;
        }
        
        vector<TreeNode *> curRow{}, nextRow{};
        int j = 1;
        
        curRow.push_back(new TreeNode{stoi(cells[0]), nullptr, nullptr});
        TreeNode *root = curRow[0];
        
        while (j < cells.size()) {
                for (int i = 0; j < cells.size() && i < 2*curRow.size(); ++i, ++j) {
                        if (cells[j] != "null") {
                                TreeNode *newNode = new TreeNode{stoi(cells[j]),
                                        nullptr, nullptr};
                                nextRow.push_back(newNode);
                                if (i%2==0) {
                                        curRow[i/2]->left = newNode;
                                } else {
                                        curRow[i/2]->right = newNode;
                                }
                        }
                }
                swap(curRow, nextRow);
                nextRow = {};
        }

        return root;
}

string TreeNode::to_string(TreeNode *root) {
        if (!root) {
                return "[]";
        }
        
        string res = "[";
        
        queue<TreeNode *> q{};
        q.push(root);
        int found = 0, prev_found;
        while (found >= 0) {
                prev_found = found;
                found = -1;
                int s = q.size();
                for (int i = 0; i <= s && !q.empty(); ++i) {                
                        auto t = q.front();
                        q.pop();
                
                        if (!t) {
                                res += "null,";
                                continue;
                        }
                
                        res += ::to_string(t->val) + ",";
                        if (t->left) {
                                found = 2*i;
                        }
                        if (t->right) {
                                found = 2*i+1;
                        }
                        q.push(t->left);
                        q.push(t->right);
                }
        }
                
        return res.substr(0,res.length()-1) + "]";
}
