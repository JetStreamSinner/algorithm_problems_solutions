#pragma once

// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
// Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers
// in the range [1, n] that do not appear in nums.

#include <vector>

class Solution {
public:
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[abs(nums[i]) - 1]  > 0) {
                nums[abs(nums[i]) - 1] = nums[abs(nums[i]) - 1] * (-1);
            }
        }

        std::vector<int> result;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] > 0) {
                result.push_back(i + 1);
            }
        }
        return result;
    }
};
