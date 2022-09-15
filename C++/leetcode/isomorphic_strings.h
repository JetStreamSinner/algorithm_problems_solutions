#pragma once

// https://leetcode.com/problems/isomorphic-strings/
// Given two strings s and t, determine if they are isomorphic.
// Two strings s and t are isomorphic if the characters in s can be replaced to get t.
//
// All occurrences of a character must be replaced with another character while preserving the order of characters.
// No two characters may map to the same character, but a character may map to itself.
//
// Example 1:
// Input: s = "egg", t = "add"
// Output: true
//
// Example 2:
// Input: s = "foo", t = "bar"
// Output: false
//
// Example 3:
// Input: s = "paper", t = "title"
// Output: true
//

class Solution {
public:

    bool isIsomorphic(const string& s, const string& t) {
        auto s_mut = s;
        auto t_mut = t;


        auto s_forwarder = s_mut.begin();
        auto t_forwarder = t_mut.begin();
        const auto s_eit = s_mut.end();

        std::unordered_map<char, char> cache;
        std::unordered_map<char, char> rv_cache;

        while (s_forwarder != s_eit) {
            const char replace_target = *t_forwarder;
            const char replace_source = *s_forwarder;

            if (cache.find(replace_target) == cache.end() && rv_cache.find(replace_source) == rv_cache.end()) {
                cache[replace_target] = replace_source;
                rv_cache[replace_source] = replace_target;
            } else if (!(cache[replace_target] == replace_source && rv_cache[replace_source] == replace_target)) {
                return false;
            }

            s_forwarder = std::next(s_forwarder);
            t_forwarder = std::next(t_forwarder);
        }
        return true;
    }
};
