#pragma once

// https://leetcode.com/problems/add-strings/description/
// Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.
// You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.
//
// Example 1:
// Input: num1 = "11", num2 = "123"
// Output: "134"
//
// Example 2:
// Input: num1 = "456", num2 = "77"
// Output: "533"
//
// Example 3:
// Input: num1 = "0", num2 = "0"
// Output: "0"

class Solution {
public:

    std::string add_zeroes(const std::string& source, std::size_t zeroes_count) {
        std::string result(source.size() + zeroes_count, '0');
        const auto copy_to = std::next(result.begin(), zeroes_count);
        std::copy(source.begin(), source.end(), copy_to);
        return result;
    }

    string addStrings(string num1, string num2)
    {
        const std::size_t num1_size = num1.size();
        const std::size_t num2_size = num2.size();
        const std::size_t length_diff = std::abs(static_cast<int32_t>(num1_size) - static_cast<int32_t>(num2_size));

        if (num1.size() > num2.size()) {
            num2 = add_zeroes(num2, length_diff);
        } else {
            num1 = add_zeroes(num1, length_diff);
        }

        auto num1_forwarder = num1.rbegin();
        auto num2_forwarder = num2.rbegin();

        const auto num1_end = num1.rend();

        const std::size_t base = 10;
        const int16_t ascii_offset = 48;

        std::string result;
        int16_t remainder = 0;
        while (num1_forwarder != num1_end) {
            const int16_t l_term = *num1_forwarder - ascii_offset;
            const int16_t r_term = *num2_forwarder - ascii_offset;

            int16_t proxy_term = l_term + r_term + remainder;
            remainder = proxy_term >= base ? 1 : 0;
            int16_t next_digit = proxy_term % base + ascii_offset;
            result.insert(0, 1, next_digit);

            num1_forwarder = std::next(num1_forwarder);
            num2_forwarder = std::next(num2_forwarder);
        }

        if (remainder > 0) {
            result.insert(0, 1, remainder + ascii_offset);
        }

        return result;
    }
};
