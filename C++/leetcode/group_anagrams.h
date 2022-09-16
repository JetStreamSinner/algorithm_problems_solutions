#pragma once

// https://leetcode.com/problems/group-anagrams/
// Given an array of strings strs, group the anagrams together. You can return the answer in any order.
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
// typically using all the original letters exactly once.
//
// Example 1:
// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
//
// Example 2:
// Input: strs = [""]
// Output: [[""]]
//
// Example 3:
// Input: strs = ["a"]
// Output: [["a"]]
//

class Solution {
public:
    vector <vector<string>> groupAnagrams(vector <string> &strs) {
        std::size_t max_id = 0;
        std::unordered_map<std::string, int> group_id;
        std::vector <std::vector<std::string>> result;

        for (std::string &str: strs) {
            std::string sorted = str;
            std::sort(sorted.begin(), sorted.end());
            if (group_id.find(sorted) == group_id.end()) {
                group_id[std::move(sorted)] = max_id;
                result.push_back({std::move(str)});
                max_id = max_id + 1;
            } else {
                std::size_t target_index = group_id.at(sorted);
                result.at(target_index).push_back(std::move(str));
            }
        }
        return result;
    }
};
