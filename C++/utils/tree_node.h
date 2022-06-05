#pragma once

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void free_tree(TreeNode* node) {
    if (!node) {
        return;
    }

    if (node->left) {
        free_tree(node->left);
    }

    if (node->right) {
        free_tree(node->right);
    }

    delete node;
}
}
