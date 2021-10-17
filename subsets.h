#pragma once

// https://leetcode.com/problems/subsets/
// Given an integer array nums of unique elements, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.

class Solution {
    std::vector<int> subsetFromMask(const std::vector<int> &source, const std::string &mask)
    {
        const auto setLength = source.size();
        const auto maskLength = mask.size();
        std::vector<int> subset;
        for (int index = 0; index < setLength; ++index) {
            if (index < maskLength) {
                if (mask.at(maskLength - index - 1) == '1')
                    subset.push_back(source.at(setLength - index - 1));
            }
        }
        return subset;
    }

    std::string sum(const std::string &accumulator, const std::string &term)
    {
        const auto digitsCount = accumulator.size();
        auto termCopy = term;
        auto fillLength = digitsCount - term.size();
        std::fill_n(std::inserter(termCopy, termCopy.begin()), fillLength, '0');
        auto remainder = 0;
        std::string result;
        for (int digitIndex = digitsCount - 1; digitIndex >= 0; --digitIndex) {
            auto currentDigit = (accumulator.at(digitIndex) - '0') + (termCopy.at(digitIndex) - '0') + remainder;
            auto nextDigit = 0;

            if (currentDigit == 0) {
                nextDigit = 0;
                remainder = 0;
            } else if (currentDigit == 1) {
                nextDigit = 1;
                remainder = 0;
            } else if (currentDigit == 2) {
                nextDigit = 0;
                remainder = 1;
            } else if (currentDigit == 3) {
                nextDigit = 1;
                remainder = 1;
            }
            result.push_back(nextDigit + '0');
        }
        if (remainder)
            result.push_back(remainder + '0');
        std::reverse(result.begin(), result.end());
        return result;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<std::vector<int>> result;
        const auto setLength = nums.size();
        const auto powerSet = pow(2, setLength);
        std::string mask = "0";
        const std::string incrementer = "1";
        for (auto index = 0; index < powerSet; ++index) {
            auto nextSubset = subsetFromMask(nums, mask);
            result.push_back(nextSubset);
            mask = sum(mask, incrementer);
        }
        return result;
    }
};