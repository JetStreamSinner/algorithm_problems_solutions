#pragma once

// https://leetcode.com/problems/path-sum/
// Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that
// adding up all the values along the path equals targetSum. A leaf is a node with no children.

#include "../utils/tree_node.h"

class Solution {
public:
    bool traverse_tree(TreeNode * node, int partialSum, int targetSum)
    {
        partialSum += node->val;

        if (!node->left && !node->right)
            return partialSum == targetSum;

        bool leftStatus = false;
        if (node->left)
            leftStatus = traverse_tree(node->left, partialSum, targetSum);

        bool rightStatus = false;
        if (node->right)
            rightStatus = traverse_tree(node->right, partialSum, targetSum);
        return leftStatus || rightStatus;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root)
            return false;
        return traverse_tree(root, 0, targetSum);
    }
};