#pragma once
// https://leetcode.com/problems/longest-substring-without-repeating-characters
// Given a string s, find the length of the longest substring without repeating characters.
//
// Example 1:
// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
//
// Example 2:
// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
//
// Example 3:
// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

#include <cstdlib>
#include <string>

class Solution {
public:
    int32_t lengthOfLongestSubstring(const std::string& source) const {
        std::unordered_map<int32_t, std::size_t> character_index;

        std::size_t startIndex = 0;
        std::size_t endIndex = startIndex;

        std::size_t max_counter = std::numeric_limits<std::size_t>::min();
        const std::size_t sourceSize = source.size();
        for (std::size_t index = 0; index < sourceSize; ++index) {
            const auto ch = source.at(index);
            if (character_index.find(ch) != character_index.end()) {
                startIndex = std::max(startIndex, character_index.at(ch) + 1);
                character_index.at(ch) = index;
            } else {
                character_index[ch] = index;
            }
            endIndex = endIndex + 1;
            max_counter = std::max(max_counter, endIndex - startIndex);
        }
        return static_cast<int32_t>(max_counter);    }
};