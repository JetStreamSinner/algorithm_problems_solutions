#pragma once

// https://leetcode.com/problems/contains-duplicate-ii/
// Given an integer array nums and an integer k, return true if there are two distinct indices i and j
// in the array such that nums[i] == nums[j] and abs(i - j) <= k.
//
// Example 1:
// Input: nums = [1,2,3,1], k = 3
// Output: true
//
// Example 2:
// Input: nums = [1,0,1,1], k = 1
// Output: true
//
// Example 3:
// Input: nums = [1,2,3,1,2,3], k = 2
// Output: false
//

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_map<int, int> value_index;

        const std::size_t nums_count = nums.size();
        for (std::size_t index = 0; index < nums_count; ++index) {
            const int value = nums.at(index);

            if (value_index.find(value) != value_index.end()) {
                const std::size_t prev_index = value_index.at(value);
                if (std::abs<int>(prev_index - index) <= k) {
                    return true;
                }
            }
            value_index[value] = index;
        }
        return false;
    }
};
