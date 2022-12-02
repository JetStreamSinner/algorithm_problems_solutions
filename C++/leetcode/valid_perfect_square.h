#pragma once

// https://leetcode.com/problems/valid-perfect-square/
// Given a positive integer num, write a function which returns True if num is a perfect square else False.
//
// Follow up: Do not use any built-in library function such as sqrt.
//
// Example 1:
// Input: num = 16
// Output: true
//
// Example 2:
// Input: num = 14
// Output: false

class Solution {
public:
    bool isPerfectSquare(int num) {
        long long left = 1;
        long long right = num;
        while (left <= right) {
            long long middle = (left + right) / 2;
            long long middle_square = middle * middle;
            if (middle_square == num) {
                return true;
            } else if (middle_square < num) {
                left = middle;
                left++;
            } else if (middle_square > num) {
                right = middle;
                right--;
            }
        }
        return false;
    }
};
