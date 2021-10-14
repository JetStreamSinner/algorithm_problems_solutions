#pragma once

// Given an unsorted array of integers nums, return the length
// of the longest consecutive elements sequence.
// You must write an algorithm that runs in O(n) time.

class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        std::unordered_set<int> uniqueValues;
        for (auto value : values)
            uniqueValues.insert(value);

        int maxSequence = 0;
        int maxItem = 0;
        for (auto item : values) {
            int currentSequence = 0;

            int lower = item - 1;
            while (uniqueValues.find(lower) != uniqueValues.end()) {
                currentSequence += 1;
                uniqueValues.erase(lower);
                lower = lower - 1;
            }

            int upper = item;
            while (uniqueValues.find(upper) != uniqueValues.end()) {
                currentSequence += 1;
                uniqueValues.erase(upper);
                upper = upper + 1;
            }

            maxSequence = std::max(maxSequence, currentSequence);
        }

        return maxSequence;
    }
};