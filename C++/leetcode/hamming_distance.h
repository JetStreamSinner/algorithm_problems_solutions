#pragma once

// https://leetcode.com/problems/hamming-distance/description/
// The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
//
// Given two integers x and y, return the Hamming distance between them.
//
// Example 1:
// Input: x = 1, y = 4
// Output: 2
// Explanation:
// 1   (0 0 0 1)
// 4   (0 1 0 0)
// ↑   ↑
// The above arrows point to positions where the corresponding bits are different.
//
// Example 2:
// Input: x = 3, y = 1
// Output: 1

class Solution {
public:
    int32_t hammingDistance(int32_t x, int32_t y) {
        const int32_t mask = 0x1;
        int32_t distance = 0;
        while (x || y) {
            const bool x_bit = x & mask;
            const bool y_bit = y & mask;
            if (x_bit != y_bit) {
                distance++;
            }
            x >>= 1;
            y >>= 1;
        }
        return distance;
    }
};
