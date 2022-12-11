#pragma once

// https://leetcode.com/problems/running-sum-of-1d-array/description/
// Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).
// Return the running sum of nums.
//
// Example 1:
// Input: nums = [1,2,3,4]
// Output: [1,3,6,10]
// Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].
//
// Example 2:
// Input: nums = [1,1,1,1,1]
// Output: [1,2,3,4,5]
// Explanation: Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].
//
// Example 3:
// Input: nums = [3,1,2,10,1]
// Output: [3,4,6,16,17]

class Solution {
public:

    std::vector<int32_t> additional_space_impl(const std::vector<int32_t>& nums) {
        std::vector<int32_t> prefix_sums(nums.size(), 0);
        std::size_t accumulator = 0;

        auto forwarder = nums.begin();
        auto prefix_forwarder = prefix_sums.begin();
        const auto end = nums.end();

        while (forwarder < end) {
            accumulator += *forwarder;
            *prefix_forwarder = accumulator;
            prefix_forwarder = std::next(prefix_forwarder);
            forwarder = std::next(forwarder);
        }
        return prefix_sums;
    }

    std::vector<int32_t> constant_space_impl(std::vector<int32_t>& nums) {
        auto previous = nums.begin();
        auto current = std::next(previous);
        const auto end = nums.end();


        while (current < end) {
            *current += *previous;

            current = std::next(current);
            previous = std::next(previous);
        }
        return nums;
    }

    std::vector<int> runningSum(std::vector<int32_t>& nums) {
        return additional_space_impl(nums);
    }
};