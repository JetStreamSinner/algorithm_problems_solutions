#pragma once

// https://leetcode.com/problems/balanced-binary-tree/
// Given a binary tree, determine if it is height-balanced.
// For this problem, a height-balanced binary tree is defined as:
// a binary tree in which the left and right subtrees of every node differ in height by no more than 1.


class Solution {
public:
    bool isBalanced(TreeNode *root) {
        return node_balanced(root);
    }

private:

    bool node_balanced(TreeNode *node) {
        // Empty node is balanced as default vase
        if (!node) {
            return true;
        }

        int left = node_height(node->left);
        int right = node_height(node->right);

        const bool current_node_is_balanced = std::abs(left - right) <= 1;
        if (current_node_is_balanced) {
            return node_balanced(node->left) && node_balanced(node->right);
        } else {
            return false;
        }
        return true;
    }

    int node_height(TreeNode *node) {
        if (!node) {
            return 0;
        }

        int height = 1;
        int left = node_height(node->left);
        int right = node_height(node->right);

        return height + std::max(left, right);
    }
};