#pragma once

// https://www.codewars.com/kata/520b9d2ad5c005041100000f
// Move the first letter of each word to the end of it, then add "ay" to the end of the word. Leave punctuation marks untouched.


#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <cctype>
#include "../utils/pretty_print.h"

class Solution
{

public:
    std::string pig_it(const std::string &str)
    {
        const auto tokens = tokenize(str);

        std::string result;
        const auto suffix = "ay";

        auto forwarder = tokens.begin();
        const auto endIterator = tokens.end();
        for (; forwarder != endIterator; ++forwarder) {

            bool currentLast = std::next(forwarder) == endIterator;
            std::string ender = (currentLast ? "" : " ");

            bool singleCharacter = forwarder->size() == 1;

            if (singleCharacter) {
                bool punctCharacter = std::ispunct(forwarder->at(0));

                if (punctCharacter)
                    result += *forwarder + ender;
                else
                    result += *forwarder + suffix + ender;

                continue;
            }

            const auto start = forwarder->begin();
            const auto next = std::next(start);
            const auto end = forwarder->end();

            std::string firstCharacter(start, next);
            std::string appendable(next, end);

            std::stringstream handledToken;
            handledToken << appendable << *start << suffix << ender;
            result += handledToken.str();
        }
        return result;
    }

    std::vector<std::string> tokenize(const std::string &source)
    {
        std::stringstream ss(source);
        std::istream_iterator<std::string> forwarder(ss);
        std::istream_iterator<std::string> endIterator;

        std::vector<std::string> tokens;
        std::copy(forwarder, endIterator, std::back_inserter(tokens));
        return std::move(tokens);
    }
};