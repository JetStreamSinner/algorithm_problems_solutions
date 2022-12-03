#pragma once

// https://leetcode.com/problems/first-unique-character-in-a-string/description/
// Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
//
// Example 1:
// Input: s = "leetcode"
// Output: 0
//
// Example 2:
// Input: s = "loveleetcode"
// Output: 2
//
// Example 3:
// Input: s = "aabb"
// Output: -1
//

class Solution {
public:

    int firstUniqChar(const std::string &s) {
        std::unordered_map<char, std::size_t> char_stat;

        const std::size_t str_size = s.size();
        const std::size_t wrong_index = std::numeric_limits<std::size_t>::max();

        for (std::size_t index = 0; index < str_size; ++index) {
            const char current_ch = s.at(index);
            if (char_stat.find(current_ch) != char_stat.end()) {
                char_stat.at(current_ch) = wrong_index;
            } else {
                char_stat[current_ch] = index;
            }
        }

        auto target = std::min_element(char_stat.begin(), char_stat.end(), [](const auto &left, const auto &right) {
            return left.second < right.second;
        });

        if (target->second == wrong_index) {
            return -1;
        }
        return target->second;
    }
};
