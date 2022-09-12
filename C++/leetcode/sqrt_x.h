#pragma once

class Solution {
public:
    int mySqrt(int number) {
        return binary_search(number);
    }

private:

    long long int binary_search(int target) {
        long long int lower = 0;
        long long int upper = target;
        long long int middle = lower + (upper - lower) / 2;
        long long int result = -1;

        while (lower <= upper) {
            long long int square = middle * middle;
            if (square == target) {
                return middle;
            } else if (square < target) {
                result = middle;
                lower = middle + 1;
            } else {
                upper = middle - 1;
            }
            middle = lower + (upper - lower) / 2;
        }
        return result;
    }
};