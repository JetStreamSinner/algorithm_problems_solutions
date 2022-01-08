#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>

class Solution
{
    int longestChunkedPalindrome(const std::string &text)
    {
        std::string forwardWord;
        std::string backwardWord;

        if (text.empty())
            return 0;
        if (text.length() == 1)
            return 1;

        auto forwardIterator = text.begin();
        auto backwardIterator = std::prev(text.end(), 1);

        auto leftBoundIterator = forwardIterator;
        auto rightBoundIterator = backwardIterator;

        auto chunkCounter = 0;
        do {
            if (std::string(leftBoundIterator, forwardIterator) == std::string(backwardIterator, rightBoundIterator)) {
                chunkCounter++;
                leftBoundIterator = forwardIterator;
                rightBoundIterator = backwardIterator;
            }

            forwardIterator = std::next(forwardIterator, 1);
            backwardIterator = std::prev(backwardIterator, 1);
        } while (forwardIterator < backwardIterator && std::next(forwardIterator, 1) != backwardIterator);

        return chunkCounter;
    }
};

// CHECK_TEST_CASE(std::to_string(7), firstResult, "Default case")
// CHECK_TEST_CASE(std::to_string(1), secondResult, "Only one chunk")
// CHECK_TEST_CASE(std::to_string(11), thirdResult, "Many chuncks")
// CHECK_TEST_CASE(std::to_string(3), fourthResult, "String from same characters")
// CHECK_TEST_CASE(std::to_string(6), fifthResult, "Middle split")
// CHECK_TEST_CASE(std::to_string(1), sixthResult, "One character")
// CHECK_TEST_CASE(std::to_string(0), seventhResult, "Empty string")
// CHECK_TEST_CASE(std::to_string(1), eightResult, "Not splitable string")
// CHECK_TEST_CASE(std::to_string(2), ninthResult, "Two characters split on two string")
// CHECK_TEST_CASE(std::to_string(1), tenthResult, "Two characters split in one")