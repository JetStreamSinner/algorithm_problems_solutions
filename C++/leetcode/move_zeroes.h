#pragma once

// https://leetcode.com/problems/move-zeroes
// Given an integer array nums, move all 0's to the end of it while maintaining
// the relative order of the non-zero elements.
// Note that you must do this in-place without making a copy of the array.

#include <vector>

class Solution {
public:

    void stlWayImplementation(std::vector<int> &nums) {
        auto zeroes_from = std::remove(nums.begin(), nums.end(), 0);
        std::fill(zeroes_from, nums.end(), 0);
    }

    void moveZeroes(std::vector<int> &nums) {
        return stlWayImplementation(nums);
    }
};