#pragma once

// https://leetcode.com/problems/find-pivot-index/description/
// Given an array of integers nums, calculate the pivot index of this array.
// The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal
// to the sum of all the numbers strictly to the index's right.
// If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left.
// This also applies to the right edge of the array.
// Return the leftmost pivot index. If no such index exists, return -1.
//
// Example 1:
//
// Input: nums = [1,7,3,6,5,6]
// Output: 3
// Explanation:
// The pivot index is 3.
// Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
// Right sum = nums[4] + nums[5] = 5 + 6 = 11
//
// Example 2:
// Input: nums = [1,2,3]
// Output: -1
// Explanation:
// There is no index that satisfies the conditions in the problem statement.
//
// Example 3:
// Input: nums = [2,1,-1]
// Output: 0
// Explanation:
// The pivot index is 0.
// Left sum = 0 (no elements to the left of index 0)
// Right sum = nums[1] + nums[2] = 1 + -1 = 0

class Solution {
public:
    template<typename It>
    void prefix_sum(It first, It last) {
        auto previous = first;
        auto current = std::next(previous);
        const auto end = last;


        while (current < end) {
            *current += *previous;

            current = std::next(current);
            previous = std::next(previous);
        }
    }

    int32_t pivotIndex(const std::vector<int32_t>& nums) {
        std::vector<int32_t> left_sum(nums);
        std::vector<int32_t> right_sum(nums);

        prefix_sum(left_sum.begin(), left_sum.end());
        prefix_sum(right_sum.rbegin(), right_sum.rend());

        auto left_forwarder = left_sum.begin();
        auto right_forwarder = right_sum.begin();
        auto end = left_sum.end();

        while (left_forwarder < end) {

            if (*left_forwarder == *right_forwarder) {
                return std::distance(left_sum.begin(), left_forwarder);
            }

            left_forwarder = std::next(left_forwarder);
            right_forwarder = std::next(right_forwarder);
        }
        return -1;
    }
};
