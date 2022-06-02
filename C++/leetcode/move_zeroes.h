#pragma once

// https://leetcode.com/problems/move-zeroes
// Given an integer array nums, move all 0's to the end of it while maintaining
// the relative order of the non-zero elements.
// Note that you must do this in-place without making a copy of the array.

#include <vector>

class Solution {
public:

    void customWayImplementation(std::vector<int> &nums) {
        const auto end_iterator = nums.end();
        auto result_forwarder = nums.begin();
        auto forwarder = nums.begin();

        while (forwarder != end_iterator) {
            auto next_non_zero = std::find_if_not(forwarder, end_iterator, [](auto value) {
                return value == 0;
            });

            if (next_non_zero == end_iterator)
                break;

            std::swap(*next_non_zero, *result_forwarder);
            forwarder = std::next(next_non_zero);
            result_forwarder = std::next(result_forwarder);
        }
    }

    void stlWayImplementation(std::vector<int> &nums) {
        auto zeroes_from = std::remove(nums.begin(), nums.end(), 0);
        std::fill(zeroes_from, nums.end(), 0);
    }

    void moveZeroes(std::vector<int> &nums) {
        return customWayImplementation(nums);
    }
};