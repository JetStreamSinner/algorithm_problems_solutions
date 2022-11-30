#pragma once

// Given an integer n, return true if it is a power of four. Otherwise, return false.
// An integer n is a power of four, if there exists an integer x such that n == 4x.

class Solution {
public:
    bool isPowerOfFour(int n) {
        const long long mask = 0b0101'0101'0101'0101'0101'0101'0101'0101;
        const bool have_even_bit = (n | mask) == mask;
        const bool have_one_even_bit = (n & n - 1) == 0;
        const bool positive = n > 0;
        return positive && have_even_bit && have_one_even_bit;
    }
};
