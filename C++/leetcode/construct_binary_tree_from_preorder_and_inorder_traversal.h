#pragma once

#include <vector>
#include "../utils/tree_node.h"

// Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder
// is the inorder traversal of the same tree, construct and return the binary tree.

class Solution {
public:
    using It = std::vector<int>::iterator;

    TreeNode* parse_tree(const It& inorder_start, const It& inorder_end, const It& preorder_start, const It& preorder_end) {
        const int current_level_root = *preorder_start;
        auto root_position = std::find(inorder_start, inorder_end, current_level_root);

        TreeNode * node = new TreeNode(current_level_root);

        const int left_subtree_size = std::distance(inorder_start, root_position);


        auto left_subtree_preorder_start = std::next(preorder_start);
        auto left_subtree_preorder_end = std::next(left_subtree_preorder_start, left_subtree_size - 1);

        auto right_subtree_preorder_start = std::next(left_subtree_preorder_end);
        auto right_subtree_preorder_end = preorder_end;

        if (left_subtree_size) {
            node->left = parse_tree(inorder_start, root_position, left_subtree_preorder_start, left_subtree_preorder_end);
        }

        if (right_subtree_preorder_start <= right_subtree_preorder_end) {
            node->right = parse_tree(std::next(root_position), inorder_end, right_subtree_preorder_start, right_subtree_preorder_end);
        }

        return node;
    }

    TreeNode* buildTree(std::vector<int>& preorder_source, std::vector<int>& inorder_source) {
        TreeNode * root = parse_tree(inorder_source.begin(), inorder_source.end(), preorder_source.begin(), std::prev(preorder_source.end()));
        return root;
    }
};
