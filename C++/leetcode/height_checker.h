#pragma once

// https://leetcode.com/problems/height-checker/
// A school is trying to take an annual photo of all the students.
// The students are asked to stand in a single file line in non-decreasing order by height.
// Let this ordering be represented by the integer array expected
// where expected[i] is the expected height of the ith student in line.
// You are given an integer array heights representing the current order that the students are standing in.
// Each heights[i] is the height of the ith student in line (0-indexed).
// Return the number of indices where heights[i] != expected[i].

#include <vector>

class Solution {
public:

    int sort_implementation(std::vector<int>& heights) {
        auto target_heights = heights;
        std::sort(target_heights.begin(), target_heights.end());

        auto target_forwarder = target_heights.begin();
        const auto target_end = target_heights.end();
        auto input_forwarder = heights.begin();

        int result = 0;
        while (target_forwarder != target_end) {

            if (*target_forwarder != *input_forwarder) {
                ++result;
            }

            target_forwarder = std::next(target_forwarder);
            input_forwarder = std::next(input_forwarder);
        }
        return result;
    }

    int heightChecker(std::vector<int>& heights) {
        return sort_implementation(heights);
    }
};