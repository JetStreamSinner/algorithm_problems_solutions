#pragma once

// https://leetcode.com/problems/palindrome-number/
// Given an integer x, return true if x is palindrome integer.
// An integer is a palindrome when it reads the same backward as forward.
// For example, 121 is a palindrome while 123 is not.

class Solution {
public:
    bool isPalindrome(int x) {
        const bool last_digit_zero = x % 10 == 0 && x != 0;
        const bool negative_value = x < 0;
        if (negative_value || last_digit_zero) {
            return false;
        }

        int reverted_value = 0;
        while (x > reverted_value) {
            reverted_value = reverted_value * 10 + x % 10;
            x = x / 10;
        }
        return x == reverted_value || x == reverted_value / 10;
    }
};