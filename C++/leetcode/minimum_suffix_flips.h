#pragma once

// https://leetcode.com/problems/minimum-suffix-flips/
// You are given a 0-indexed binary string target of length n. You have another binary string s of length n that is
// initially set to all zeros. You want to make s equal to target.
// In one operation, you can pick an index i where 0 <= i < n and flip all bits in the inclusive range [i, n - 1].
// Flip means changing '0' to '1' and '1' to '0'.
// Return the minimum number of operations needed to make s equal to target.
//
// Example 1:
// Input: target = "10111"
// Output: 3
// Explanation: Initially, s = "00000".
//     Choose index i = 2: "00000" -> "00111"
//     Choose index i = 0: "00111" -> "11000"
//     Choose index i = 1: "11000" -> "10111"
// We need at least 3 flip operations to form target.
//
// Example 2:
// Input: target = "101"
// Output: 3
// Explanation: Initially, s = "000".
//     Choose index i = 0: "000" -> "111"
//     Choose index i = 1: "111" -> "100"
//     Choose index i = 2: "100" -> "101"
// We need at least 3 flip operations to form target.
//
// Example 3:
// Input: target = "00000"
// Output: 0
// Explanation: We do not need any operations since the initial s already equals target.


#include <string>
#include <iostream>
#include <cassert>

class Solution {
public:
    template<typename It>
    void flipRange(It first, It last)
    {
        static_assert(std::is_same<typename It::value_type, char>());
        assert(first <= last);

        constexpr char zero_character = '0';
        constexpr char one_character = '1';
        while (first < last) {
            *first = (*first == zero_character) ? (one_character) : (zero_character);
            first = std::next(first);
        }
    }

    template<typename It>
    It findRangeEnd(It first1, It last1, It first2, It last2)
    {
        const auto distance1 = std::distance(first1, last1);
        const auto distance2 = std::distance(first2, last2);
        assert(distance1 == distance2);

        std::size_t flipsCount = 0;
        while (first1 < last1 && *first1 != *first2) {
            flipsCount++;
            first1 = std::next(first1);
            first2 = std::next(first2);
        }

        if (flipsCount == 0) {
            return std::mismatch(first1, last1, first2, last2).first;
        }

        return first1;
    }

    int minFlipsDirectSolution(std::string& source)
    {
        std::reverse(source.begin(), source.end());
        std::string target(source.size(), '0');

        std::size_t counter = 0;
        while (target != source) {
            auto target_miss = findRangeEnd(target.begin(), target.end(), source.begin(), source.end());
            flipRange(target.begin(), target_miss);
            ++counter;
        }

        return counter;
    }

    int minFlips(std::string& source) {
        return minFlipsDirectSolution(source);
    }
};
