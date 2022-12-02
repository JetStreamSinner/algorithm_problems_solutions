#pragma once


// https://leetcode.com/problems/reverse-vowels-of-a-string/
// Given a string s, reverse only all the vowels in the string and return it.
// The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

class Solution {
public:
    string reverseVowels(string s)
    {
        const std::string vowels = "aeiouAEIOU";
        for (std::size_t left = 0, right = s.size() - 1; left < right; ) {
            left = s.find_first_of(vowels, left);
            right = s.find_last_of(vowels, right);

            if (left >= right) {
                break;
            }

            swap(s.at(left), s.at(right));
            left++;
            right--;
        }
        return s;
    }

};
