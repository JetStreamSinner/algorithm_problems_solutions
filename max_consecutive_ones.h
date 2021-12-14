#pragma once

#include <vector>

// https://leetcode.com/problems/max-consecutive-ones/
// Given a binary array nums, return the maximum number of consecutive 1's in the array.

class Solution {
public:
    int findMaxConsecutiveOnes(std::vector<int>& nums)
    {
        auto forwarder = nums.begin();
        const auto last = nums.end();

        auto sequence_length = 0;
        auto max_sequence_length = 0;

        while (forwarder != last) {
            if (*forwarder == 1) {
                sequence_length += 1;
            } else {
                max_sequence_length = std::max(max_sequence_length, sequence_length);
                sequence_length = 0;
            }
            ++forwarder;
        }

        return std::max(max_sequence_length, sequence_length);
    }
};