#pragma once

// https://leetcode.com/problems/validate-binary-search-tree/description/
// Given the root of a binary tree, determine if it is a valid binary search tree (BST).
// A valid BST is defined as follows:
// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool validate_subtree(TreeNode * root, TreeNode * lower, TreeNode * upper) {
        if (!root) {
            return true;
        }

        if ((lower != nullptr && root->val <= lower->val) || (upper != nullptr && root->val >= upper->val)) {
            return false;
        }

        return validate_subtree(root->right, root, upper) && validate_subtree(root->left, lower, root);
    }

    bool isValidBST(TreeNode* root) {
        return validate_subtree(root, nullptr, nullptr);
    }
};
