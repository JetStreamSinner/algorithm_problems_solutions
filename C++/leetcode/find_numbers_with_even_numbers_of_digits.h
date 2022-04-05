#pragma once

#include <vector>
#include <algorithm>

class Solution {
public:

    int digitsCount(int value)
    {
        int digitsCounter = 0;
        while (value != 0) {
            value /= 10;
            ++digitsCounter;
        }
        return digitsCounter;
    }

    int findNumbers(std::vector<int>& nums)
    {
        auto evenDigits = 0;
        std::for_each(nums.begin(), nums.end(), [&](auto value) {
            if (digitsCount(value) % 2 == 0)
                ++evenDigits;
        });
        return evenDigits;
    }
};