#pragma once
// https://leetcode.com/problems/check-if-n-and-its-double-exist/
// Given an array arr of integers,
// check if there exists two integers N and M
// such that N is the double of M ( i.e. N = 2 * M).

#include <vector>
#include <unordered_set>

class Solution {
public:

    bool non_constant_space_impl(std::vector<int>& arr) {
        std::unordered_set<int> values_doubles;
        return std::any_of(arr.begin(), arr.end(), [&](auto value) {
            const bool result = values_doubles.find(value) != values_doubles.end();
            const int doubled_value = value * 2;
            values_doubles.insert(doubled_value);
            bool value_even = value % 2 == 0;
            if (value_even) {
                const int halfed_value = value / 2;
                values_doubles.insert(halfed_value);
            }
            return result;
        });
    }

    bool checkIfExist(std::vector<int>& arr) {
        return non_constant_space_impl(arr);
    }
};