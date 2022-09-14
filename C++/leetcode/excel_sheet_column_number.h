#pragma once

// https://leetcode.com/problems/excel-sheet-column-number/
// Given a string columnTitle that represents the column title as appears in an Excel sheet, return its corresponding column number.
// For example:
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
// Input: columnTitle = "A"
// Output: 1
//
// Example 2:
// Input: columnTitle = "AB"
// Output: 28
//
// Example 3:
// Input: columnTitle = "ZY"
// Output: 701
//

class Solution {
public:
    int titleToNumber(const string &columnTitle) {
        const int base = 26;
        const int ascii_offset = 65;

        int result = 0;
        const std::size_t size = columnTitle.size();
        for (int index = size - 1, base_power = 0; index >= 0; --index, ++base_power) {
            const char ch = int(columnTitle.at(index) - ascii_offset + 1);
            const int next_item = static_cast<int>(ch) * pow(base, base_power);
            result += next_item;
        }
        return result;
    }
};
