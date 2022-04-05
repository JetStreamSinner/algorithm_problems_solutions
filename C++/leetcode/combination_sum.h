#pragma once
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

// https://leetcode.com/problems/combination-sum/
// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target.
// You may return the combinations in any order.
// The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
// It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.


class Solution
{
public:

    template<typename Vector>
    void backtrack(int startIndex, Vector &&current, std::vector<std::vector<int>> &result, const std::vector<int> &candidates, int target)
    {
        if (target == 0) {
            result.push_back(current);
        } else {
            const auto itemsCount = candidates.size();
            for (auto index = startIndex; index < itemsCount && target >= candidates.at(index); ++index) {
                current.push_back(candidates.at(index));
                backtrack(index, current, result, candidates, target - candidates.at(index));
                current.pop_back();
            }
        }
    }

    std::vector<std::vector<int>> combinationSum(const std::vector<int>& candidates, int target)
    {
        auto source = candidates;
        std::sort(source.begin(), source.end());
        const auto itemsCount = source.size();

        std::vector<std::vector<int>> result;
        backtrack(0, std::vector<int>{}, result, source, target);

        return result;
    }
};