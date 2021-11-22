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

    int calculateVectorSum(const std::vector<int> &vec)
    {
        auto result = 0;
        for (auto value : vec)
            result += value;
        return result;
    }

    template<typename T>
    bool compareVectorsItems(const std::vector<T> &v1, const std::vector<T> &v2)
    {
        auto fst = v1;
        std::sort(fst.begin(), fst.end());

        auto scnd = v2;
        std::sort(scnd.begin(), scnd.end());

        return fst == scnd;
    }

    bool containSame(const std::vector<std::vector<int>> &source, const std::vector<int> &vec)
    {
        return std::any_of(source.begin(), source.end(), [&](const auto &sourceItem){
            return compareVectorsItems(sourceItem, vec);
        });
    }

    template<typename Vector>
    void backtrack(int startIndex, Vector &&current, std::vector<std::vector<int>> &result, const std::vector<int> &candidates, int target)
    {
        int currentCombinationSum = calculateVectorSum(current);

        if (currentCombinationSum > target) {
            return;
        } else if (currentCombinationSum == target) {
            if (!containSame(result, current))
                result.push_back(current);
            return;
        }

        const auto itemsCount = candidates.size();
        for (auto index = startIndex; index < itemsCount; ++index) {

            if (current.empty() && index != startIndex)
                return;

            current.push_back(candidates.at(index));
            backtrack(startIndex, current, result, candidates, target);
            current.pop_back();
        }
    }

    std::vector<std::vector<int>> combinationSum(const std::vector<int>& candidates, int target)
    {
        const auto itemsCount = candidates.size();
        std::vector<std::vector<int>> result;

        for (auto index = 0; index < itemsCount; ++index)
            backtrack(index, std::vector<int>{}, result, candidates, target);

        return result;
    }
};