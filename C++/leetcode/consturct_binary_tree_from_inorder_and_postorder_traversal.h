#pragma once

// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
// Given two integer arrays inorder and postorder where inorder is the inorder traversal of
// a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

#include <vector>
#include "../utils/tree_node.h"

class Solution {
public:
    using It = std::vector<int>::iterator;

    TreeNode* parse_tree(const It& inorder_start, const It& inorder_end, const It& postorder_start, const It& postorder_end) {
        const int current_level_root = *postorder_end;
        const auto root_position = std::find(inorder_start, inorder_end, current_level_root);

        TreeNode * node = new TreeNode(current_level_root);

        const int left_subtree_size = std::distance(inorder_start, root_position);

        auto left_subtree_postorder_start = postorder_start;
        auto left_subtree_postorder_end = std::next(left_subtree_postorder_start, left_subtree_size - 1);

        auto right_subtree_postorder_start = std::next(left_subtree_postorder_end);
        auto right_subtree_postorder_end = std::prev(postorder_end);

        if (inorder_start < root_position) {
            node->left = parse_tree(inorder_start, root_position, left_subtree_postorder_start, left_subtree_postorder_end);
        }

        if (right_subtree_postorder_start <= right_subtree_postorder_end) {
            node->right = parse_tree(std::next(root_position), inorder_end, right_subtree_postorder_start, right_subtree_postorder_end);
        }

        return node;
    }

    TreeNode* buildTree(std::vector<int>& inorder_source, std::vector<int>& postorder_source) {
        TreeNode * root = parse_tree(inorder_source.begin(), inorder_source.end(), postorder_source.begin(), std::prev(postorder_source.end()));
        return root;
    }};
