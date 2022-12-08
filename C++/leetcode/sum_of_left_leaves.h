#pragma once

// https://leetcode.com/problems/sum-of-left-leaves/description/
// Given the root of a binary tree, return the sum of all left leaves.
//
// A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.
//
// Example 1:
//
// Input: root = [3,9,20,null,null,15,7]
// Output: 24
// Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.
//
// Example 2:
//
// Input: root = [1]
// Output: 0

// Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
class Solution {
public:

    void traverse_tree(TreeNode * node, bool node_is_left, int32_t& accumulator) {
        if (!node->left && !node->right && node_is_left) {
            accumulator += node->val;
        }
        if (node->left) {
            traverse_tree(node->left, true, accumulator);
        }
        if (node->right) {
            traverse_tree(node->right, false, accumulator);
        }
    }

    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int32_t accumulator = 0;
        if (root->left) {
            traverse_tree(root->left, true, accumulator);
        }

        if (root->right) {
            traverse_tree(root->right, false, accumulator);
        }

        return accumulator;
    }
};
