#pragma once

// https://leetcode.com/problems/maximum-depth-of-binary-tree/
// Given the root of a binary tree, return its maximum depth.
// A binary tree's maximum depth is the number of nodes along
// the longest path from the root node down to the farthest leaf node.

#include <queue>
#include "../utils/tree_node.h"

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }

        std::queue<TreeNode*> current_level;
        current_level.push(root);

        auto counter = 0;
        while (!current_level.empty()) {
            const int nodesCount = current_level.size();

            for (int index = 0; index < nodesCount; ++index) {
                auto current_node =  current_level.front();
                current_level.pop();

                if (current_node->left) {
                    current_level.push(current_node->left);
                }
                if (current_node->right) {
                    current_level.push(current_node->right);
                }
            }
            ++counter;
        }
        return counter;
    }
};