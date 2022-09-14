#pragma once

// https://leetcode.com/problems/excel-sheet-column-title/
// Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.
//
// For example:
//
// A -> 1
// B -> 2
// C -> 3
// ...
// Z -> 26
// AA -> 27
// AB -> 28
// ...
//
// Example 1:
// Input: columnNumber = 1
// Output: "A"
//
// Example 2:
// Input: columnNumber = 28
// Output: "AB"
//
// Example 3:
// Input: columnNumber = 701
// Output: "ZY"
//

class Solution {
public:
    std::string convertToTitle(int columnNumber) {
        const int base = 26;
        const int upper_ascii_offset = 65;
        std::string result;

        while (columnNumber) {
            const char next_digit = (columnNumber - 1) % base + upper_ascii_offset;
            result.push_back(next_digit);
            columnNumber = (columnNumber - 1) / base;
        }

        std::reverse(result.begin(), result.end());
        return result;
    }
};
