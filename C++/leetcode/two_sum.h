#pragma once

// https://leetcode.com/problems/two-sum
// Given an array of integers nums and an integer target,
// return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

class Solution {
public:
    std::vector<int32_t> twoSum(std::vector<int32_t>& nums, int32_t target) {
        std::unordered_map<int32_t, int32_t> seen;

        const auto numsCount = nums.size();
        for (int32_t index = 0; index < numsCount; ++index) {
            if (seen.find(target - nums.at(index)) != seen.end())
                return {seen[target - nums.at(index)], index};
            seen[nums.at(index)] = index;
        }
        return {};
    }
};