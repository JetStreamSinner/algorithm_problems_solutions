#pragma once

#include <unordered_map>

// https://leetcode.com/problems/generate-parentheses/
// Generate Parentheses
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.


class GenerateParentheses {
public:

    void generateParenthesisImpl(std::vector<std::string> &result, std::string tempString, char currentCharacter,
                                 std::unordered_map<char, int> &pairs, int openedCount) {
        auto tempPairs = pairs;
        tempPairs.at(currentCharacter)--;
        tempString += currentCharacter;

        if (currentCharacter == '(')
            ++openedCount;
        else if (currentCharacter == ')')
            --openedCount;

        auto leftBracketsCount = tempPairs.at('(');
        auto rightBracketsCount = tempPairs.at(')');

        if (leftBracketsCount == 0 && rightBracketsCount == 0)
            result.push_back(tempString);

        if (leftBracketsCount != 0) {
            generateParenthesisImpl(result, tempString, '(', tempPairs, openedCount);
        }

        if (rightBracketsCount != 0) {
            if (openedCount < 1)
                return;
            generateParenthesisImpl(result, tempString, ')', tempPairs, openedCount);
        }
    }

    std::vector<std::string> generateParenthesis(int pairsCount) {
        std::unordered_map<char, int> pairs = {
                {'(', pairsCount},
                {')', pairsCount}
        };
        std::vector<std::string> result;
        generateParenthesisImpl(result, "", '(', pairs, 0);

        return result;
    }

};
