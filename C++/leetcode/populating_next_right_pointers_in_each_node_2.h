#pragma once

// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
// Given a binary tree
// struct Node {
//     int val;
//     Node *left;
//     Node *right;
//     Node *next;
// }
// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
// Initially, all next pointers are set to NULL.

// Definition for a Node.
// class Node {
// public:
//     int val;
//     Node* left;
//     Node* right;
//     Node* next;
//
//     Node() : val(0), left(NULL), right(NULL), next(NULL) {}
//     Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
//     Node(int _val, Node* _left, Node* _right, Node* _next)
//         : val(_val), left(_left), right(_right), next(_next) {}
// };

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) {
            return nullptr;
        }

        std::queue<Node*> tree_level;

        tree_level.push(root);

        while (!tree_level.empty()) {
            std::size_t level_size = tree_level.size();

            Node * prev = tree_level.front();
            tree_level.pop();

            for (std::size_t node_index = 0; node_index < level_size; ++node_index) {
                Node * current = nullptr;
                if (!tree_level.empty() && node_index < level_size - 1) {
                    current = tree_level.front();
                    tree_level.pop();
                }

                if (prev->left) {
                    tree_level.push(prev->left);
                }

                if (prev->right) {
                    tree_level.push(prev->right);
                }

                prev->next = current;
                prev = current;
            }

        }

        return root;
    }
};
