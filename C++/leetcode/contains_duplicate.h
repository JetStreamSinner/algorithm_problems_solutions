#pragma once

// https://leetcode.com/problems/contains-duplicate/submissions/861153645/
// Given an integer array nums, return true if any value appears at least twice
// in the array, and return false if every element is distinct.

class Solution {
public:
    bool containsDuplicate(const std::vector<int32_t>& nums) {
        std::unordered_map<int32_t, int32_t> itemsCounter;
        for (const int32_t val : nums) {
            itemsCounter[val]++;
            if (itemsCounter[val] > 1)
                return true;
        }
        return false;

    }
};
