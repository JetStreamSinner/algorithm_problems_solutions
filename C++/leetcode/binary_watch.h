#pragma once

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