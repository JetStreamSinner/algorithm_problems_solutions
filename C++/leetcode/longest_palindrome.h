#pragma once

// https://leetcode.com/problems/longest-palindrome/description/
// Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome
// that can be built with those letters.
// Letters are case-sensitive, for example, "Aa" is not considered a palindrome here.
//
// Example 1:
// Input: s = "abccccdd"
// Output: 7
// Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
//
// Example 2:
// Input: s = "a"
// Output: 1
// Explanation: The longest palindrome that can be built is "a", whose length is 1.

class Solution {
public:
    int hash_map_solution(const std::string& s) {
        std::unordered_map<char, std::size_t> char_appearance;

        std::size_t result_length = 0;
        for (auto ch : s) {
            char_appearance[ch]++;
            const std::size_t count = char_appearance[ch];
            if (count % 2 == 0 && count != 0) {
                result_length += 2;
            }
        }

        for (const auto& [ch, count] : char_appearance) {
            if (count % 2 == 1) {
                result_length += 1;
                break;
            }
        }
        return result_length;
    }

    int greedy_solution(const std::string& s) {
        const std::size_t ascii_table_size = 256;
        std::array<int32_t, ascii_table_size> letters_count{0};

        for (auto ch : s) {
            letters_count.at(ch)++;
        }

        std::size_t result = 0;
        for (auto ch_count : letters_count) {
            result += ch_count / 2 * 2;
            if (result % 2 == 0 && ch_count % 2 == 1) {
                result++;
            }
        }
        return result;
    }

    int longestPalindrome(const string& s) {
        return greedy_solution(s);
    }
};
