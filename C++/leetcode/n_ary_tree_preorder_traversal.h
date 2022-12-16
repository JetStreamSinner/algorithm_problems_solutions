#pragma once

// https://leetcode.com/problems/n-ary-tree-preorder-traversal/description/
// Given the root of an n-ary tree, return the preorder traversal of its nodes' values.
// Nary-Tree input serialization is represented in their level order traversal.
// Each group of children is separated by the null value (See examples)

class Solution {
public:
    void traverse_tree(Node * node, std::vector<int32_t>& nodes_values) {
        nodes_values.push_back(node->val);

        for (auto child : node->children) {
            if (child) {
                traverse_tree(child, nodes_values);
            }
        }
    }

    std::vector<int> preorder(Node* root) {
        if (!root) {
            return {};
        }
        std::vector<int32_t> result;
        traverse_tree(root, result);
        return result;
    }
};
