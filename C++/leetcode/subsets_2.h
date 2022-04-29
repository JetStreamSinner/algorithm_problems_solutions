#pragma once

#include <vector>
#include <set>

// https://leetcode.com/problems/subsets-ii/
// Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.

class Solution {
public:

    void subsetForIndex(std::vector<int>& source, std::vector<std::vector<int>>& result, std::vector<int>& temp, int targetIndex) {
        const auto appendItem = source.at(targetIndex);
        temp.push_back(appendItem);
        result.push_back(temp);

        const auto sourceSize = source.size();
        for (auto index = targetIndex + 1; index < sourceSize; ++index) {
            if (index > targetIndex + 1 && source.at(index) == source.at(index - 1))
                continue;
            subsetForIndex(source, result, temp, index);
        }
        temp.pop_back();
    }

    std::vector<std::vector<int>> subsetsWithDup(const std::vector<int> &nums) {
        auto source = nums;
        std::sort(source.begin(), source.end());

        std::vector<std::vector<int>> result;
        std::vector<int> temp;

        result.emplace_back();
        const auto numsCount = nums.size();
        for (auto index = 0; index < numsCount; ++index) {

            if (index > 0 && source.at(index) == source.at(index - 1))
                continue;
            subsetForIndex(source, result, temp, index);
        }

        return result;
    }
};
