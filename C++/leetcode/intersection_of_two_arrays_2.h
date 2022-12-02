#pragma once

// https://leetcode.com/problems/intersection-of-two-arrays-ii
// Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.
// Example 1:
// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2,2]
//
// Example 2:
// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [4,9]
// Explanation: [9,4] is also accepted.

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_map<int, int> value_appear;
        for (auto value : nums1) {
            value_appear[value]++;
        }

        std::vector<int> result;
        for (auto value : nums2) {
            if (value_appear.find(value) != value_appear.end() && value_appear.at(value) != 0) {
                result.push_back(value);
                value_appear.at(value)--;
            }
        }

        return result;
    }
};
