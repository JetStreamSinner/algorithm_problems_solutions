#pragma once

// https://leetcode.com/problems/convert-a-number-to-hexadecimal/description/
// Given an integer num, return a string representing its hexadecimal representation.
// For negative integers, two’s complement method is used.
// All the letters in the answer string should be lowercase characters, and there should not be any leading zeros
// in the answer except for the zero itself.
// Note: You are not allowed to use any built-in library method to directly solve this problem.
//
// Example 1:
// Input: num = 26
// Output: "1a"
//
// Example 2:
// Input: num = -1
// Output: "ffffffff"

class Solution {
public:
    std::string toHex(int32_t num) {

        if (num == 0) {
            return "0";
        }

        uint32_t val = static_cast<uint32_t>(num);

        const std::string hex_table = "0123456789abcdef";
        // Binary representation of this mask is 000...001111
        const char mask = 0xF;

        std::string result;
        while (val) {
            const std::size_t ch_index = val & mask;
            const char next_ch = hex_table[ch_index];
            result.insert(0, 1, next_ch);
            val = val >> 4;
        }
        return result;
    }
};