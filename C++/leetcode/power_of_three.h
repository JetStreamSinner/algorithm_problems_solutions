#pragma once

// Given an integer n, return true if it is a power of three. Otherwise, return false.
// An integer n is a power of three, if there exists an integer x such that n == 3x.

class Solution {
public:
    bool isPowerOfThree(long long n) {
        long long target = 1;
        while (target < n) {
            target = target * 3;
        }
        return target == n;
    }
};
