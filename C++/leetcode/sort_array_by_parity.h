#pragma once

// https://leetcode.com/problems/sort-array-by-parity/
// Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.
// Return any array that satisfies this condition.

#include <vector>

class Solution {
public:
    bool is_even(int value) {
        return value % 2 == 0;
    }

    bool is_odd(int value) {
        return !is_even(value);
    }

    std::vector<int> sortArrayByParity(std::vector<int>& nums) {
        auto first = nums.begin();
        auto second = nums.begin();
        const auto end_iterator = nums.end();

        while (first != end_iterator && second != end_iterator) {
            if (is_odd(*first)) {
                auto next_even = std::find_if(std::max(second, first), end_iterator, [&](auto value) {
                    return is_even(value);
                });

                if (next_even == end_iterator) {
                    break;
                }

                std::swap(*first, *next_even);

                second = next_even;
            } else {
                first = std::next(first);
            }
        }
        return std::move(nums);
    }
};