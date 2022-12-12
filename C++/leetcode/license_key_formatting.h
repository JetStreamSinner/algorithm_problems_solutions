#pragma once

// https://leetcode.com/problems/license-key-formatting/description/
// You are given a license key represented as a string s that consists of only alphanumeric characters and dashes. The string is separated into n + 1 groups by n dashes. You are also given an integer k.
//
// We want to reformat the string s such that each group contains exactly k characters, except for the first group, which could be shorter than k but still must contain at least one character. Furthermore, there must be a dash inserted between two groups, and you should convert all lowercase letters to uppercase.
//
// Return the reformatted license key.
//
// Example 1:
// Input: s = "5F3Z-2e-9-w", k = 4
// Output: "5F3Z-2E9W"
// Explanation: The string s has been split into two parts, each part has 4 characters.
// Note that the two extra dashes are not needed and can be removed.
//
// Example 2:
// Input: s = "2-5g-3-J", k = 2
// Output: "2-5G-3J"
// Explanation: The string s has been split into three parts, each part has 2 characters except the first part as it could be shorter as mentioned above.

class Solution {
public:

    template<typename It>
    It getNextKey(It key_start, It key_source_end, int32_t required_size)
    {
        std::size_t key_size = 0;
        while (key_size < required_size && key_start < key_source_end) {
            key_start = std::next(key_start);
            ++key_size;
        }
        return key_start;
    }

    std::string licenseKeyFormatting(std::string& source, int32_t key_size) {
        auto remove_from = std::remove(source.begin(), source.end(), '-');
        source.erase(remove_from, source.end());
        std::transform(source.begin(), source.end(), source.begin(), ::toupper);

        if (source.empty()) {
            return "";
        }

        auto backwarder = source.rbegin();
        const auto end = source.rend();

        std::string result;
        const char splitter = '-';
        while (backwarder < end) {
            auto next_key_end = getNextKey(backwarder, end, key_size);
            source.insert(next_key_end.base(), splitter);
            backwarder = next_key_end;
        }
        result.pop_back();
        return result;
    }
};
