#pragma once

// https://leetcode.com/problems/binary-tree-paths/
// Given the root of a binary tree, return all root-to-leaf paths in any order.
// A leaf is a node with no children.

class Solution {
public:
    void traversal(TreeNode *node, std::vector<int> &path, std::vector <std::string> &result) {
        path.push_back(node->val);

        if (!node->left && !node->right) {
            std::string temp;

            auto forwarder = path.begin();
            const auto eit = path.end();

            while (forwarder != std::prev(eit)) {
                temp += std::to_string(*forwarder) + "->";
                forwarder = std::next(forwarder);
            }
            temp += std::to_string(*forwarder);
            result.push_back(temp);
            return;
        }


        if (node->left) {
            traversal(node->left, path, result);
            path.pop_back();
        }
        if (node->right) {
            traversal(node->right, path, result);
            path.pop_back();
        }

    }

    vector <string> binaryTreePaths(TreeNode *root) {
        if (!root)
            return {};

        std::vector <std::string> result;
        std::vector<int> path;
        traversal(root, path, result);
        return result;
    }
};
