#pragma once

// https://leetcode.com/problems/symmetric-tree/
// Given the root of a binary tree, check
// whether it is a mirror of itself (i.e., symmetric around its center).

#include <queue>
#include "../utils/tree_node.h"
#include "../utils/pretty_print.h"

class Solution {
public:

    bool is_symmetric(TreeNode * left, TreeNode * right) {
        if (!left || !right)
            return left == right;

        if (left->val != right->val) {
            return false;
        }

        return is_symmetric(left->left, right->right) && is_symmetric(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return false;
        }
        return is_symmetric(root->left, root->right);
    }
};