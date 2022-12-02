#pragma once


// https://leetcode.com/problems/reverse-vowels-of-a-string/
// Given a string s, reverse only all the vowels in the string and return it.
// The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

class Solution {
public:
    string reverseVowels(string s) {
        auto forwarder = s.begin();
        auto backwarder = std::prev(s.end());

        while (forwarder < backwarder) {
            while (!isVowel(*forwarder) && forwarder < backwarder) {
                forwarder = std::next(forwarder);
            }

            while (!isVowel(*backwarder) && forwarder < backwarder) {
                backwarder = std::prev(backwarder);
            }

            std::swap(*forwarder, *backwarder);

            forwarder = std::next(forwarder);
            backwarder = std::prev(backwarder);
        }
        return s;
    }

    bool isVowel(char ch) {
        const std::unordered_set<char> vowels = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        return vowels.find(ch) != vowels.end();
    }
};
