#pragma once

// https://leetcode.com/problems/squares-of-a-sorted-array/
// Given an integer array nums sorted in non-decreasing order,
// return an array of the squares of each number sorted in non-decreasing order.

#include <vector>
#include <cmath>

class Solution {
public:
    std::vector<int> sort_impl(std::vector<int>& nums) {
        std::for_each(nums.begin(), nums.end(), [](auto &value) {
            value *= value;
        });
        std::sort(nums.begin(), nums.end());
        return std::move(nums);
    }

    int sqr(int value) {
        return value * value;
    }

    std::vector<int> two_pointers_impl(std::vector<int>& nums) {
        auto left = nums.begin();
        auto right = std::prev(nums.end());

        std::vector<int> result(nums.size());
        auto back_inserter = result.rbegin();

        while (left <= right) {
            const int left_sqr = sqr(*left);
            const int right_sqr = sqr(*right);
            if (left_sqr < right_sqr) {
                *back_inserter = right_sqr;
                right = std::prev(right);
            } else {
                *back_inserter = left_sqr;
                left = std::next(left);
            }
            back_inserter = std::next(back_inserter);
        }
        return std::move(result);
    }

    std::vector<int> sortedSquares(std::vector<int>& nums) {
        return std::move(two_pointers_impl(nums));
    }
};