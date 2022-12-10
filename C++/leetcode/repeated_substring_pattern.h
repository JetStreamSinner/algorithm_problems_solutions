#pragma once

// https://leetcode.com/problems/repeated-substring-pattern/
// Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.
//
// Example 1:
// Input: s = "abab"
// Output: true
// Explanation: It is the substring "ab" twice.
//
// Example 2:
// Input: s = "aba"
// Output: false
//
// Example 3:
// Input: s = "abcabcabcabc"
// Output: true
// Explanation: It is the substring "abc" four times or the substring "abcabc" twice.


class Solution {
public:

    bool pattern_reachability(const std::string_view& s, const std::string_view& pattern) {
        const std::size_t pattern_size = pattern.size();
        const std::size_t source_size = s.size();
        for (std::size_t pattern_index = 0; pattern_index * pattern_size < source_size; ++pattern_index) {
            const std::string_view probe_pattern = s.substr(pattern_index * pattern_size, pattern_size);
            if (probe_pattern != pattern) {
                return false;
            }
        }
        return true;
    }

    bool repeatedSubstringPattern(const string& s) {
        const std::string_view view(s);
        const std::size_t size = view.size();
        for (std::size_t substring_size = 1; substring_size <= size / 2; ++substring_size) {
            const std::string_view pattern = view.substr(0, substring_size);
            bool pattern_reached = pattern_reachability(s, pattern);
            if (pattern_reached) {
                return true;
            }
        }
        return false;
    }
};
