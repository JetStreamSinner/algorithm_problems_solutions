#pragma once

// https://leetcode.com/problems/valid-palindrome/
// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
// Given a string s, return true if it is a palindrome, or false otherwise.
//
// Example 1:
// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.
//
// Example 2:
// Input: s = "race a car"
// Output: false
// Explanation: "raceacar" is not a palindrome.
//
// Example 3:
// Input: s = " "
// Output: true
// Explanation: s is an empty string "" after removing non-alphanumeric characters.
// Since an empty string reads the same forward and backward, it is a palindrome.


class Solution {
public:
    bool isPalindrome(const string &source) {
        std::string s = source;
        auto remove_from = std::remove_if(s.begin(), s.end(), [](char ch) {
            return !isalnum(ch);
        });

        if (remove_from != s.end()) {
            s.erase(remove_from, s.end());
        }

        const int middle_offset = s.size() / 2;
        const auto middle_item = std::next(s.begin(), middle_offset);
        return std::equal(s.begin(), middle_item, s.rbegin(), [](char first, char second) {
            return std::tolower(first) == std::tolower(second);
        });
    }
};
