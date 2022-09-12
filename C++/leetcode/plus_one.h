#pragma once

// https://leetcode.com/problems/plus-one/
// You are given a large integer represented as an integer array digits,
// where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least
// significant in left-to-right order. The large integer does not contain any leading 0's.
// Increment the large integer by one and return the resulting array of digits.
//
// Example 1:
// Input: digits = [1,2,3]
// Output: [1,2,4]
// Explanation: The array represents the integer 123.
// Incrementing by one gives 123 + 1 = 124.
// Thus, the result should be [1,2,4].
//
// Example 2:
// Input: digits = [4,3,2,1]
// Output: [4,3,2,2]
// Explanation: The array represents the integer 4321.
// Incrementing by one gives 4321 + 1 = 4322.
// Thus, the result should be [4,3,2,2].
//
// Example 3:
// Input: digits = [9]
// Output: [1,0]
// Explanation: The array represents the integer 9.
// Incrementing by one gives 9 + 1 = 10.
// Thus, the result should be [1,0].


#include <vector>

class Solution {
public:
    std::vector<int> plusOne(const std::vector<int>& digits) {
        auto digits_mut = digits;

        auto forwarder = digits_mut.rbegin();
        const auto eit = digits_mut.rend();

        int remainder = 1;
        const int digit_overflow = 10;
        for (;forwarder != eit;) {
            const int current_digit = *forwarder + remainder;
            if (current_digit == digit_overflow) {
                *forwarder = 0;
                remainder = 1;
                forwarder = std::next(forwarder);
            } else {
                *forwarder = current_digit;
                remainder = 0;
                break;
            }
        }
        if (remainder) {
            digits_mut.insert(digits_mut.begin(), remainder);
        }
        return std::move(digits_mut);
    }
};