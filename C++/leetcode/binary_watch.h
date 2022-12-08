#pragma once

// https://leetcode.com/problems/binary-watch/
// A binary watch has 4 LEDs on the top to represent the hours (0-11), and 6 LEDs on the bottom to represent
// the minutes (0-59). Each LED represents a zero or one, with the least significant bit on the right.
// For example, the below binary watch reads "4:51".
// Given an integer turnedOn which represents the number of LEDs that are currently on (ignoring the PM),
// return all possible times the watch could represent. You may return the answer in any order.
// The hour must not contain a leading zero.
// For example, "01:00" is not valid. It should be "1:00".
// The minute must be consist of two digits and may contain a leading zero.
// For example, "10:2" is not valid. It should be "10:02".

// Example 1:
// Input: turnedOn = 1
// Output: ["0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00"]

// Example 2:
// Input: turnedOn = 9
// Output: []


#include <cmath>
#include <sstream>
#include <iomanip>

class Solution {
public:
    std::string build_time_string(int32_t hours, int32_t minutes) {
        std::stringstream time_builder;
        time_builder << hours << ":" << std::setw(2) << std::setfill('0') << minutes;
        return std::move(time_builder.str());
    }

    int32_t oneBitCount(uint32_t val) {
        std::size_t counter = 0;
        const uint32_t last_bit_checker = 1;
        while (val) {
            if (val & last_bit_checker) {
                counter = counter + 1;
            }
            val = val >> 1;
        }
        return counter;
    }

    void calculate_times(std::vector<std::string>& result, int32_t hour, int32_t bits_on_minutes) {
        const std::size_t minutes_constraint = 63;
        for (std::size_t minutes_index = 0; minutes_index <= minutes_constraint; ++minutes_index) {
            int32_t remain_bits = oneBitCount(minutes_index) - bits_on_minutes;
            if (remain_bits == 0) {
                const auto time_string = build_time_string(hour, minutes_index);
                result.push_back(time_string);
            }
        }
    }

    std::vector<std::string> readBinaryWatch(int turnedOn) {
        std::vector<std::string> result;
        const std::size_t hours_constraint = 11;
        for (std::size_t hour_index = 0; hour_index <= hours_constraint; ++hour_index) {
            int32_t bits_on_minutes = turnedOn - oneBitCount(hour_index);
            calculate_times(result, hour_index, bits_on_minutes);
        }
        return result;
    }
};