#pragma once

// https://leetcode.com/problems/binary-search/
// Given an array of integers nums which is sorted in ascending order, and an integer target, write a function
// to search target in nums. If target exists, then return its index. Otherwise, return -1.
// You must write an algorithm with O(log n) runtime complexity.


class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto it = std::lower_bound(nums.begin(), nums.end(), target);
        if (it == nums.end() || *it != target)
            return -1;
        else
            return std::distance(nums.begin(), it);
    }
};