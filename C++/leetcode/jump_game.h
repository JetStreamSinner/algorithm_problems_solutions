#pragma once

// https://leetcode.com/problems/jump-game
// You are given an integer array nums.
// You are initially positioned at the array's first index,
// and each element in the array represents your maximum jump length at that position.
// Return true if you can reach the last index, or false otherwise.

class Solution {
public:
    bool canJump(const std::vector<int32_t>& nums) {
        std::size_t max_jump_index = 0;

        const std::size_t num_length = nums.size();
        for (std::size_t index = 0; index < num_length; ++index) {
            max_jump_index = std::max(index + nums.at(index), max_jump_index);
            if (max_jump_index < index + 1) {
                break;
            }
        }

        return max_jump_index >= num_length - 1;
    }
};
