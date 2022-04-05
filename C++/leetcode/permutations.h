#pragma once

// https://leetcode.com/problems/permutations/
// Given an array nums of distinct integers, return all the possible permutations.
// You can return the answer in any order.

class Solution {
public:

    template<typename T>
    void permutationForIndex(int startIndex, T &&temp, std::vector<std::vector<int>> &permutationAccumulator, const std::vector<int> &source, std::vector<bool> &used)
    {
        bool permutationDone = temp.size() == source.size();
        if (permutationDone) {
            permutationAccumulator.push_back(temp);
            return;
        }

        if (startIndex >= source.size())
            return;

        const auto numsCount = source.size();
        for (auto index = 0; index < numsCount; ++index) {
            if (used.at(index))
                continue;
            temp.push_back(source.at(index));
            used.at(index) = true;

            permutationForIndex(index, temp, permutationAccumulator, source, used);

            used.at(index) = false;
            temp.pop_back();
        }
    }

    std::vector<std::vector<int>> permute(std::vector<int>& nums)
    {
        std::vector<std::vector<int>> result;
        const auto numsCount = nums.size();
        for (auto index = 0; index < numsCount; ++index) {
            std::vector<bool> used(numsCount);
            used.at(index) = true;
            permutationForIndex(index, std::vector<int>{nums.at(index)}, result, nums, used);
        }
        return result;
    }
};