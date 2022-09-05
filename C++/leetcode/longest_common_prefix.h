#pragma once

// https://leetcode.com/problems/longest-common-prefix/
// Write a function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string "".
//
// Example 1:
// Input: strs = ["flower","flow","flight"]
// Output: "fl"
//
// Example 2:
// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.
//

#include <string>
#include <vector>
#include <algorithm>


class Solution {
public:
    std::string longestCommonPrefix(const std::vector<std::string> &strs) {
        const auto min_item_iter = std::min_element(strs.begin(), strs.end(), [](auto& lhs, auto& rhs) {
            return lhs.size() < rhs.size();
        });
        if (min_item_iter == strs.end()) {
            return "";
        }
        auto min_item = *min_item_iter;
        const std::size_t min_length = min_item.size();

        for (std::size_t index = 0; index < min_length; ++index) {
            const auto character_to_compare = min_item.at(index);
            for (auto& str : strs) {
                if (str.at(index) != character_to_compare) {
                    return { min_item.begin(), std::next(min_item.begin(), index) };
                }
            }
        }
        return std::move(min_item);
    }
};