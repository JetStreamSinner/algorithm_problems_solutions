#pragma once


class Solution {
public:
    int mySqrt(int number) {
        for (std::size_t value = 0; value <= number / 2 + 1; ++value) {
            if (value * value == number) {
                return value;
            } else if (value * value > number) {
                return value - 1;
            }
        }
        return -1;
    }
};