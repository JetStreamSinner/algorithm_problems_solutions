#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>

#define CHECK_TEST_CASE(expect, result, description) \
    std::cout << "Description: " << description << \
    ". Verdict: " << (expect == result ? \
    "Success. Expect: " + expect + " result: " + result :                                      \
    "Wrong. Expect: " + expect + " result: " + result                                          \
    ) << std::endl;

int solution(std::string text)
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

int main(int argc, char * argv[])
{
    auto firstResult = std::to_string(solution("ghiabcdefhelloadamhelloabcdefghi"));
    CHECK_TEST_CASE(std::to_string(7), firstResult, "Default case")

    auto secondResult = std::to_string(solution("merchant"));
    CHECK_TEST_CASE(std::to_string(1), secondResult, "Only one chunk")

    auto thirdResult = std::to_string(solution("antaprezatepzapreanta"));
    CHECK_TEST_CASE(std::to_string(11), thirdResult, "Many chuncks")

    auto fourthResult = std::to_string(solution("aaa"));
    CHECK_TEST_CASE(std::to_string(3), fourthResult, "String from same characters")

    auto fifthResult = std::to_string(solution("bqrcnnqrcb"));
    CHECK_TEST_CASE(std::to_string(6), fifthResult, "Middle split")

    auto sixthResult = std::to_string(solution("a"));
    CHECK_TEST_CASE(std::to_string(1), sixthResult, "One character")

    auto seventhResult = std::to_string(solution(""));
    CHECK_TEST_CASE(std::to_string(0), seventhResult, "Empty string")

    auto eightResult = std::to_string(solution("abc"));
    CHECK_TEST_CASE(std::to_string(1), eightResult, "Not splitable string")

    auto ninthResult = std::to_string(solution("aa"));
    CHECK_TEST_CASE(std::to_string(2), ninthResult, "Two characters split on two string")

    auto tenthResult = std::to_string(solution("ab"));
    CHECK_TEST_CASE(std::to_string(1), tenthResult, "Two characters split in one")
    return 0;
}