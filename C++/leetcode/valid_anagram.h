#pragma once

// https://leetcode.com/problems/valid-anagram/
// Given two strings s and t, return true if t is an anagram of s, and false otherwise.
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
// typically using all the original letters exactly once.
//
// Example 1:
// Input: s = "anagram", t = "nagaram"
// Output: true
//
// Example 2:
// Input: s = "rat", t = "car"
// Output: false
//

class Solution {
public:
    bool isAnagram(string& s, string& t) {

        // Also we can just sort this string and compare him

        if (s.size() != t.size()) {
            return false;
        }

        std::unordered_map<char, int> character_occurance;

        std::for_each(s.begin(), s.end(), [&character_occurance](char ch) {
            character_occurance[ch] += 1;
        });

        std::for_each(t.begin(), t.end(), [&character_occurance](char ch) {
            character_occurance[ch] -= 1;
            if (character_occurance.at(ch) <= 0) {
                character_occurance.erase(ch);
            }
        });
        return character_occurance.empty();
    }
};
