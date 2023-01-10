#pragma once

// https://leetcode.com/problems/serialize-and-deserialize-binary-tree
// Serialization is the process of converting a data structure or object into a sequence of bits so that it can be
// stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the
// same or another computer environment.
// Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your
// serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized
// to a string and this string can be deserialized to the original tree structure.
// Clarification: The input/output format is the same as how LeetCode serializes a binary tree.
// You do not necessarily need to follow this format, so please be creative and come up with different
// approaches yourself.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    std::string serialize(TreeNode* root) {
        if (!root) {
            return {};
        }

        std::queue<TreeNode*> nodes;
        nodes.push(root);

        std::stringstream blob_builder;
        blob_builder << root->val << " ";
        while (!nodes.empty()) {
            TreeNode * node = nodes.front();
            nodes.pop();

            if (node->left) {
                blob_builder << node->left->val << " ";
                nodes.push(node->left);
            } else {
                blob_builder << "null" << " ";
            }

            if (node->right) {
                blob_builder << node->right->val << " ";
                nodes.push(node->right);
            } else {
                blob_builder << "null" << " ";
            }
        }
        std::string serialized = std::move(blob_builder.str());
        std::string temp = {serialized.begin(), serialized.end() - 1};

        return temp;
    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(const std::string& data) {
        if (data.empty()) {
            return nullptr;
        }
        const std::string null_token = "null";
        std::stringstream serialized(data);

        TreeNode * root = nullptr;
        std::queue<TreeNode**> nodes;
        nodes.push(&root);

        while (!serialized.eof()) {
            std::string token;
            serialized >> token;

            TreeNode ** node = nodes.front();
            nodes.pop();

            if (token == null_token) {
                continue;
            }

            int32_t node_value = std::atoi(token.c_str());
            *node = new TreeNode(node_value);
            nodes.push(&(*node)->left);
            nodes.push(&(*node)->right);
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));