#pragma once

// https://leetcode.com/problems/binary-tree-preorder-traversal/
// https://leetcode.com/problems/binary-tree-inorder-traversal/
// https://leetcode.com/problems/binary-tree-postorder-traversal/
// Given the root of a binary tree, return traversal

#include <vector>

template<typename T>
struct TreeNode {
    TreeNode * left;
    TreeNode * right;
    T val;
};

template<typename Strategy>
class Solution {
public:
    std::vector<int> traverseTree(TreeNode<int>* root) {
        if (!root) {
            return {};
        }
        std::vector<int> result;
        _impl->traverseTree(root, result);
        return std::move(result);
    }
private:
    Strategy _impl;
};

template<typename T>
class PreorderStrategy {
public:
    void traverse(TreeNode<T> * node, std::vector<T>& result) {
        const int value = node->val;
        result.push_back(value);

        if (node->left) {
            traverseTree(node->left, result);
        }

        if (node->right) {
            traverseTree(node->right, result);
        }
    }
};

template<typename T>
class InorderStrategy {
public:
    void traverse(TreeNode<T> * node, std::vector<T>& result) {
        if (node->left) {
            traverseTree(node->left, result);
        }

        const int value = node->val;
        result.push_back(value);

        if (node->right) {
            traverseTree(node->right, result);
        }
    }
};

template<typename T>
class PostorderStrategy {
public:
    void traverse(TreeNode<T> * node, std::vector<T>& result) {
        if (node->left) {
            traverseTree(node->left, result);
        }

        if (node->right) {
            traverseTree(node->right, result);
        }
        const int value = node->val;
        result.push_back(value);
    }
};
