#pragma once

// https://leetcode.com/problems/climbing-stairs
// You are climbing a staircase. It takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

class Solution {
public:
    int fibonaci(int targetIndex)
    {
        int32_t prev = 1;
        int32_t current = 2;

        if (targetIndex == 0)
            return 0;

        if (targetIndex == 1 || targetIndex == 2)
            return prev;

        for (int32_t itemIndex = 3; itemIndex < targetIndex; ++itemIndex) {
            int32_t next = current + prev;
            prev = current;
            current = next;
        }
        return current;
    }

    int climbStairs(int n) {
        return fibonaci(n);
    }
};
