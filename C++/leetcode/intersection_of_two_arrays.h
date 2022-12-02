#pragma once

// https://leetcode.com/problems/intersection-of-two-arrays/description/
// Given two integer arrays nums1 and nums2, return an array of their intersection.
// Each element in the result must be unique and you may return the result in any order.

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_set<int> uniques;
        std::copy(nums1.begin(), nums1.end(), std::inserter(uniques, uniques.begin()));

        std::unordered_set<int> result;
        std::copy_if(nums2.begin(), nums2.end(), std::inserter(result, result.begin()), [&uniques](int value) {
            return uniques.find(value) != uniques.end();
        });

        return {result.begin(), result.end()};
    }
};
