#pragma once

#include <cstdlib>
#include <algorithm>

// https://leetcode.com/problems/jump-game-ii
// You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].
//
// Each element nums[i] represents the maximum length of a forward jump from index i. In other words,
// if you are at nums[i], you can jump to any nums[i + j] where:
// - 0 <= j <= nums[i] and
// - i + j < n
//
// Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

class Solution {
public:
    int32_t jump(const std::vector<int32_t>& nums) {
        int32_t nums_size = nums.size();
        std::vector<int32_t> can_reach_index(nums);

        for (int32_t index = 1; index < nums_size; ++index) {
            can_reach_index.at(index) = std::max(can_reach_index.at(index - 1), index + can_reach_index.at(index));
        }

        std::size_t jumps = 0;

        for (int32_t next_index = 0; next_index < nums_size - 1; next_index = can_reach_index.at(next_index)) {
            jumps++;
        }
        return jumps;
    }
};
