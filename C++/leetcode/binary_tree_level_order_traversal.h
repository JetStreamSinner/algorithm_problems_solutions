#pragma once
// https://leetcode.com/problems/binary-tree-level-order-traversal/

#include <vector>
#include <queue>
#include "../utils/tree_node.h"

class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode * root) {
        if (!root) {
            return {};
        }

        std::queue<TreeNode*> nodes;
        nodes.push(root);

        std::queue<int> levels;
        const int start_level = 0;
        levels.push(start_level);

        std::vector<std::vector<int>> result;

        while (!nodes.empty()) {
            const auto node = nodes.front();

            const int value = node->val;
            const int value_level = levels.front();

            if (result.size() <= value_level) {
                result.push_back(std::vector<int>());
            }
            result.at(value_level).push_back(value);

            nodes.pop();
            levels.pop();

            if (node->left) {
                nodes.push(node->left);
                levels.push(value_level + 1);
            }

            if (node->right) {
                nodes.push(node->right);
                levels.push(value_level + 1);
            }
        }

        return result;
    }
};