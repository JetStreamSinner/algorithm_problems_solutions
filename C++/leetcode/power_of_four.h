#pragma once

// Given an integer n, return true if it is a power of four. Otherwise, return false.
// An integer n is a power of four, if there exists an integer x such that n == 4x.

class Solution {
public:
    bool isPowerOfFour(int n) {
        long long target = 1;
        while (target < n) {
            target = target * 4;
        }
        return target == n;
    }
};
