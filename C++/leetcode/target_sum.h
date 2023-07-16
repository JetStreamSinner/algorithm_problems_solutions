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

struct PairHash {
public:
    template<typename T1, typename T2>
    int32_t operator()(const std::pair<T1, T2> &pair) const {
        return std::hash<T1>{}(pair.first) ^ std::hash<T2>{}(pair.second);
    }
};

template<typename T>
struct SizeComparator {
    bool operator()(const T &left, const T &right) const {
        return (left.first == right.first && left.second == right.second);
    }
};

class Solution
{
public:
    int32_t findTargetSumWays(std::vector<int32_t>& nums, int32_t target) const
    {
        std::unordered_map<std::pair<int32_t, int32_t>, int32_t, PairHash, SizeComparator<std::pair<int32_t, int32_t>>> memo;
        return findTargetSumWaysImpl(nums, target, nums.size() - 1, 0, memo);
    }
private:
    int32_t findTargetSumWaysImpl(const std::vector<int32_t>& nums, int32_t target, int32_t index, int32_t currSum, std::unordered_map<std::pair<int32_t, int32_t>, int32_t, PairHash, SizeComparator<std::pair<int32_t, int32_t>>>& memo) const
    {
        if (memo.count({index, currSum})) {
            return memo.at({index, currSum});
        }

        const int32_t traverseFinished = (index < 0);

        if (traverseFinished && currSum == target) {
            return 1;
        }

        if (traverseFinished) {
            return 0;
        }

        const int32_t positive = findTargetSumWaysImpl(nums, target, index - 1, currSum + nums.at(index), memo);
        const int32_t negative = findTargetSumWaysImpl(nums, target, index - 1, currSum - nums.at(index), memo);
        memo[{index, currSum}] = positive + negative;

        return memo[{index, currSum}];
    }
};
