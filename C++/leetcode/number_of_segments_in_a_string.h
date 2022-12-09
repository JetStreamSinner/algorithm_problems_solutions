#pragma once

// https://leetcode.com/problems/number-of-segments-in-a-string/description/
// Given a string s, return the number of segments in the string.
// A segment is defined to be a contiguous sequence of non-space characters.
//
// Example 1:
// Input: s = "Hello, my name is John"
// Output: 5
// Explanation: The five segments are ["Hello,", "my", "name", "is", "John"]
//
// Example 2:
// Input: s = "Hello"
// Output: 1

class Solution {
public:

    std::size_t countSegments(const std::string& s) {
        if (s.empty()) {
            return 0;
        }
        const char separator = ' ';
        auto first_meaningful = s.find_first_not_of(separator, 0);
        auto last_meaningful = s.find_last_not_of(separator, s.size());

        if (first_meaningful > last_meaningful || first_meaningful == std::string::npos && last_meaningful == std::string::npos) {
            return 0;
        }

        const auto text_start_from = std::next(s.begin(), first_meaningful);
        const auto text_end_at = std::next(s.begin(), last_meaningful);
        std::string trimmed(text_start_from, text_end_at);
        std::stringstream ss(trimmed);

        std::size_t result = 0;
        std::string token;
        while (!ss.eof()) {
            ss >> token;
            result += 1;
        }

        return result;
    }
};