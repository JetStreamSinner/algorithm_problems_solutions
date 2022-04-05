#pragma once

// https://leetcode.com/problems/combinations/
// Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].
// You may return the answer in any order.

class Solution {
public:

    template<typename T>
    void combine(int startIndex, std::vector<std::vector<int>> &result, T &&combination, int targetLength, int upperBound)
    {
        if (combination.size() == targetLength) {
            result.push_back(combination);
            return;
        }

        for (auto index = startIndex + 1; index <= upperBound; ++index) {
            combination.push_back(index);
            combine(index, result, combination, targetLength, upperBound);
            combination.pop_back();
        }
    }

    std::vector<std::vector<int>> combine(int upperBound, int combinationLength)
    {
        const auto lowerBound = 1;
        std::vector<std::vector<int>> result;
        for (auto index = lowerBound; index <= upperBound; ++index)
            combine(index, result, std::vector<int>{ index }, combinationLength, upperBound);
        return result;
    }
};