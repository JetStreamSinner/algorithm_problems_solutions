#pragma once

#include <vector>
#include <algorithm>
#include <ctype.h>

// Given a string s, we can transform every letter individually to be lowercase or uppercase to create another string.
// Return a list of all possible strings we could create. You can return the output in any order.

struct LetterState
{
    int index;
    int state;
};

int bitsCount(const std::vector<LetterState> &mask)
{
    int counter = 0;
    for (auto letter : mask)
        counter += letter.state;
    return counter;
}

void nextMask(std::vector<LetterState> &mask)
{
    const auto digitsCount = mask.size();
    std::vector<int> term;
    std::fill_n(std::back_inserter(term), digitsCount, 0);
    term.back() = 1;

    auto remainder = 0;
    for (int digitIndex = digitsCount - 1; digitIndex >= 0; --digitIndex) {
        auto currentDigit = term.at(digitIndex) + mask.at(digitIndex).state + remainder;
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
        }
        mask.at(digitIndex).state = nextDigit;
    }
}

std::string permutationFromMask(const std::string &source, const std::vector<LetterState> &mask)
{
    std::string result = source;
    for (auto letter : mask) {
        if (letter.state)
            result.at(letter.index) = toupper(source.at(letter.index));
        else
            result.at(letter.index) = tolower(source.at(letter.index));
    }
    return result;
}

class Solution {
public:
    std::vector<std::string> letterCasePermutation(std::string &source)
    {
        std::for_each(source.begin(), source.end(), [](char &ch) {
            ch = std::tolower(ch);
        });
        std::vector<LetterState> mask;

        const auto lettersCount = source.size();
        for (auto index = 0; index < lettersCount; ++index) {
            bool charIsDigit = !isdigit(source.at(index));
            if (charIsDigit) {
                LetterState letter {index, 0};
                mask.push_back(letter);
            }
        }

        std::vector<std::string> result { source };
        int enabledBits = 0;
        const auto maskLength = mask.size();
        while (enabledBits != maskLength) {
            nextMask(mask);
            auto nextPermutation = permutationFromMask(source, mask);
            result.push_back(nextPermutation);
            enabledBits = bitsCount(mask);
        }

        return result;
    }
};