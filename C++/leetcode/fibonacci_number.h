#pragma once

// https://leetcode.com/problems/fibonacci-number

class Solution {
public:
    int32_t fib(int32_t targetIndex) {
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
};
