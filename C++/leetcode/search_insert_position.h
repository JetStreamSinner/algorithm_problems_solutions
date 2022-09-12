#pragma once

// https://leetcode.com/problems/search-insert-position/
// Given a sorted array of distinct integers and a target value, return the index if the target is found.
// If not, return the index where it would be if it were inserted in order.
// You must write an algorithm with O(log n) runtime complexity.

#include <vector>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        const auto position = std::lower_bound(nums.begin(), nums.end(), target);
        int insertion_offset = std::distance(nums.begin(), position);
        return insertion_offset;
    }
};