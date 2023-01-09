#pragma once

// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
// You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:
//
// struct Node {
//     int val;
//     Node *left;
//     Node *right;
//     Node *next;
// }
//
// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
// Initially, all next pointers are set to NULL.

class Solution {
public:

    void connect_nodes(Node * left, Node * right) {
        if (!left && !right) {
            return;
        }

        if (left) {
            connect_nodes(left->left, left->right);
        }
        if (right) {
            connect_nodes(right->left, right->right);
        }
        if (left && right) {
            left->next = right;
            connect_nodes(left->right, right->left);
        }
    }

    Node * recursive_solution(Node * root) {
        if (!root) {
            return nullptr;
        }

        connect_nodes(root->left, root->right);

        return root;
    }

    Node * iterative_solution(Node * root) {
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

    Node * connect(Node* root) {
        return iterative_solution(root);
    }
};