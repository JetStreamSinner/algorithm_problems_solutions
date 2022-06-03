#pragma once

// https://leetcode.com/problems/third-maximum-number/
// Given an integer array nums, return the third distinct maximum number in this array.
// If the third maximum does not exist, return the maximum number.

#include <vector>

class Solution {
public:
    int thirdMax(std::vector<int>& nums) {
        std::optional<int> first_max = std::nullopt;
        std::optional<int> second_max = std::nullopt;
        std::optional<int> third_max = std::nullopt;

        auto forwarder = nums.begin();
        const auto end_iter = nums.end();

        while (forwarder != end_iter) {
            const int next_value = *forwarder;

            if (next_value > first_max) {
                third_max = second_max;
                second_max = first_max;
                first_max = next_value;
            } else if (next_value > second_max && next_value != first_max) {
                third_max = second_max;
                second_max = next_value;
            } else if (next_value > third_max && next_value != first_max && next_value != second_max) {
                third_max = next_value;
            }

            forwarder = std::next(forwarder);
        }
        return third_max.has_value() ? third_max.value() : first_max.value();
    }
};