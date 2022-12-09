#pragma once

// https://leetcode.com/problems/arranging-coins/description/
// You have n coins and you want to build a staircase with these coins. The staircase consists of k rows where the ith row has exactly i coins. The last row of the staircase may be incomplete.
// Given the integer n, return the number of complete rows of the staircase you will build.
//
// Example 1:
// Input: n = 5
// Output: 2
// Explanation: Because the 3rd row is incomplete, we return 2.
//
// Example 2:
// Input: n = 8
// Output: 3
// Explanation: Because the 4th row is incomplete, we return 3.

class Solution {
public:
    int arrangeCoins(int32_t n) {
        int32_t row_counter = 0;
        int32_t row_length = 1;
        while (n - row_length >= 0) {
            n -= row_length;
            row_length++;
            row_counter++;
        }
        return row_counter;
    }
};
