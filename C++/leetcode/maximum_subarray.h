#pragma once

// https://leetcode.com/problems/maximum-subarray/submissions/861153012/
// Given an integer array nums, find the
// subarray which has the largest sum and return its sum.

class Solution {
public:
    int maxSubArray(vector<int32_t>& nums) {
        int32_t largestSum = std::numeric_limits<int32_t>::min();
        int32_t subSum = largestSum;
        std::size_t numsSize = nums.size();
        for (std::size_t index = 0; index < numsSize; ++index) {
            if (subSum < 0)
                subSum = nums.at(index);
            else
                subSum += nums.at(index);
            largestSum = std::max(largestSum, subSum);
        }

        return largestSum;
    }
};
