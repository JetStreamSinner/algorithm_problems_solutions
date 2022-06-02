#pragma once

// Given an array arr, replace every element in that array with the greatest element among the elements to its right,
// and replace the last element with -1.
// After doing so, return the array.

#include <vector>
#include <numeric>

class Solution {
public:
    std::vector<int> replaceElements(std::vector<int>& arr) {
        auto reverse_forwarder = arr.rbegin();
        const auto end_iterator = arr.rend();

        int max_value = *reverse_forwarder;
        while (reverse_forwarder != end_iterator) {
            const int current_value = *reverse_forwarder;
            if (current_value > max_value) {
                *reverse_forwarder = max_value;
                max_value = current_value;
            } else {
                *reverse_forwarder = max_value;
            }
            reverse_forwarder = std::next(reverse_forwarder);
        }
        arr.back() = -1;
        return std::move(arr);
    }
};