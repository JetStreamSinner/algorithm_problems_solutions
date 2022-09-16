#pragma once

// https://leetcode.com/problems/word-pattern/
// Given a pattern and a string s, find if s follows the same pattern.
// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.
//
// Example 1:
// Input: pattern = "abba", s = "dog cat cat dog"
// Output: true
//
// Example 2:
// Input: pattern = "abba", s = "dog cat cat fish"
// Output: false
//
// Example 3:
// Input: pattern = "aaaa", s = "dog cat cat dog"
// Output: false
//

class Solution {
public:
    bool wordPattern(const string &pattern, const string &s) {

        std::stringstream ss(s);

        std::unordered_map<char, std::string> pattern_string;
        std::unordered_map<std::string, char> string_pattern;

        for (auto &pat_part: pattern) {
            std::string next_string;
            ss >> next_string;

            if (next_string.empty())
                return false;
            if (pattern_string.find(pat_part) != pattern_string.end()) {
                if (string_pattern.at(pattern_string.at(pat_part)) != pat_part)
                    return false;
                if (pattern_string.at(pat_part) != next_string)
                    return false;
            } else {
                if (string_pattern.find(next_string) != string_pattern.end())
                    return false;
                pattern_string[pat_part] = next_string;
                string_pattern[next_string] = pat_part;
            }
        }

        if (!ss.eof())
            return false;

        return true;
    }
};
