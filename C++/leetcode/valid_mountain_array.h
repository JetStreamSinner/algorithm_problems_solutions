#pragma once

// https://leetcode.com/problems/valid-mountain-array/
// Given an array of integers arr, return true if and only if it is a valid mountain array.

#include <vector>

class Solution {
public:
    bool validMountain(std::vector<int>& arr) {
        auto forwarder = arr.begin();
        const auto end_iterator = arr.end();
        auto up_start = forwarder;
        while (std::next(forwarder) != end_iterator && *forwarder < *std::next(forwarder)) {
            forwarder = std::next(forwarder);
        }
        if (forwarder == up_start || forwarder == end_iterator) {
            return false;
        }
        auto fall_start = forwarder;
        while (std::next(forwarder) != end_iterator && *forwarder > *std::next(forwarder)) {
            forwarder = std::next(forwarder);
        }
        return forwarder == std::prev(end_iterator) && forwarder != fall_start;
    }
};