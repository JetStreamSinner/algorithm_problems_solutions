#pragma once

#include <iostream>
#include <cstdlib>
#include <vector>

// https://leetcode.com/problems/target-sum/
// You are given an integer array nums and an integer target.
// You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.
// For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
// Return the number of different expressions that you can build, which evaluates to target.

// Example 1:
// Input: nums = [1,1,1,1,1], target = 3
// Output: 5
// Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
// -1 + 1 + 1 + 1 + 1 = 3
// +1 - 1 + 1 + 1 + 1 = 3
// +1 + 1 - 1 + 1 + 1 = 3
// +1 + 1 + 1 - 1 + 1 = 3
// +1 + 1 + 1 + 1 - 1 = 3
//
// Example 2:
// Input: nums = [1], target = 1
// Output: 1

class Solution
{
public:
    int32_t findTargetSumWays(std::vector<int32_t>& nums, int32_t target) const
    {
        std::unordered_map<int32_t, int32_t> memo;
        return findTargetSumWaysImpl(nums, target, 0);
    }
private:
    int32_t findTargetSumWaysImpl(const std::vector<int32_t>& nums, int32_t target, int32_t index) const
    {
        const int32_t traverseFinished = (nums.size() == index);

        if (traverseFinished && target == 0) {
            return 1;
        }

        if (traverseFinished) {
            return 0;
        }

        return findTargetSumWaysImpl(nums, target + nums.at(index), index + 1) + findTargetSumWaysImpl(nums, target - nums.at(index), index + 1);
    }
};
