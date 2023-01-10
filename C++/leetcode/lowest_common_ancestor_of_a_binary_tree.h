#pragma once

// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree
// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between
// two nodes p and q as the lowest node in T that has both p and q as descendants
// (where we allow a node to be a descendant of itself).”

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

    bool contain_node(TreeNode * root, TreeNode * target) {
        if (!root) {
            return false;
        }
        std::stack<TreeNode*> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            TreeNode * node = nodes.top();
            nodes.pop();

            if (node == target) {
                return true;
            }

            if (node->left) {
                nodes.push(node->left);
            }

            if (node->right) {
                nodes.push(node->right);
            }
        }
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode * root, TreeNode * p, TreeNode * q) {
        std::unordered_map<TreeNode*, TreeNode*> child_parent;

        TreeNode * sentinel = new TreeNode(0);
        child_parent[root] = nullptr;

        std::stack<TreeNode*> nodes;
        nodes.push(root);

        while (!nodes.empty()) {
            TreeNode * node = nodes.top();
            nodes.pop();

            if (node->left) {
                nodes.push(node->left);
                child_parent[node->left] = node;
            }

            if (node->right) {
                nodes.push(node->right);
                child_parent[node->right] = node;
            }
        }

        if (contain_node(p, q)) {
            return p;
        }

        if (contain_node(q, p)) {
            return q;
        }
        TreeNode * forwarder = child_parent.at(p);
        while (!contain_node(forwarder, q)) {
            forwarder = child_parent.at(forwarder);
        }

        if (!forwarder) {
            return root;
        }
        return forwarder;
    }
};
