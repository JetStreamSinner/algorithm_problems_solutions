#pragma once

// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
// Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.
// A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.


class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return makeBST(nums.begin(), nums.end());
    }
private:
    template<typename It>
    TreeNode * makeBST(It first, It last) {
        const int size = std::distance(first, last);

        const bool seq_empty = size == 0;
        if (seq_empty) {
            return nullptr;
        }

        const int mid_offset = size / 2;
        const auto middle = std::next(first, mid_offset);

        TreeNode * node = new TreeNode(*middle);
        node->left = makeBST(first, middle);
        node->right = makeBST(middle + 1, last);
        return node;
    }
};