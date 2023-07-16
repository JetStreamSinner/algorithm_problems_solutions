#pragma once

// https://leetcode.com/problems/all-possible-full-binary-trees/
// Given an integer n, return a list of all possible full binary trees with n nodes. Each node of each tree in the
// answer must have Node.val == 0.
// Each element of the answer is the root node of one possible tree. You may return the final list of trees in any order.
// A full binary tree is a binary tree where each node has exactly 0 or 2 children.

class Solution {
public:
    std::vector<TreeNode*> allPossibleFBT(int32_t n) {
        const bool numberIsEven = ((n % 2) == 0);
        if (numberIsEven) {
            return {};
        }

        std::unordered_map<int32_t, std::vector<TreeNode*>> memo;
        return dp(n, memo);
    }

private:
    std::vector<TreeNode*> dp(int32_t n, std::unordered_map<int32_t, std::vector<TreeNode*>>& memo)
    {
        if (memo.count(n)) {
            return memo.at(n);
        }

        if (n == 1) {
            return { new TreeNode(0) };
        }

        std::vector<TreeNode*> result;
        for (int32_t i = 1; i < n; i += 2) {
            std::vector<TreeNode*> leftSubtree = dp(i, memo);
            std::vector<TreeNode*> rightSubtree = dp(n - i - 1, memo);

            for (auto l : leftSubtree) {
                for (auto r : rightSubtree) {
                    TreeNode * root = new TreeNode(0, l, r);
                    result.push_back(root);
                }
            }
        }

        memo[n] = result;
        return memo.at(n);
    }
};