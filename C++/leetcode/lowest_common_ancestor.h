#pragma once

// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree
// Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.
// According to the definition of LCA on Wikipedia:
// “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as
// descendants (where we allow a node to be a descendant of itself).”

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        TreeNode *node = root;
        while (node) {
            if (p->val > node->val && q->val > node->val) {
                node = node->right;
            } else if (p->val < node->val && q->val < node->val) {
                node = node->left;
            } else {
                return node;
            }
        }
        return nullptr;
    }
};
