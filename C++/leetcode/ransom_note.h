#pragma once

// Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
//
// Each letter in magazine can only be used once in ransomNote.
// Example 1:
// Input: ransomNote = "a", magazine = "b"
// Output: false
//
// Example 2:
// Input: ransomNote = "aa", magazine = "ab"
// Output: false
//
// Example 3:
// Input: ransomNote = "aa", magazine = "aab"
// Output: true

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        std::unordered_map<char, int> char_appearance;
        for (auto ch : magazine) {
            char_appearance[ch]++;
        }

        for (auto ch : ransomNote) {
            if (char_appearance.find(ch) != char_appearance.end()) {
                if (char_appearance.at(ch) == 0) {
                    return false;
                }
                char_appearance.at(ch)--;
            } else {
                return false;
            }
        }
        return true;
    }
};
