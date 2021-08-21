#ifndef BALANCE_PARENTHESES_H
#define BALANCE_PARENTHESES_H

// Minimum Insertions to Balance a Parentheses String
// Given a parentheses string s containing only the characters '(' and ')'. A parentheses string is balanced if:
//     - Any left parenthesis '(' must have a corresponding two consecutive right parenthesis '))'.
//     - Left parenthesis '(' must go before the corresponding two consecutive right parenthesis '))'.
// In other words, we treat '(' as opening parenthesis and '))' as closing parenthesis.
// For example, "())", "())(())))" and "(())())))" are balanced, ")()", "()))" and "(()))" are not balanced.
// You can insert the characters '(' and ')' at any position of the string to balance it if needed.
// Return the minimum number of insertions needed to make s balanced.

class BalanceParentheses
{
public:
    int minInsertions(const std::string &bracketsStr)
    {
        int leftBracketsCounter = 0;
        int requiredRightBrackets = 0;
        int insertionsCounter = 0;

        auto forwardIterator = bracketsStr.begin();
        const auto endIterator = bracketsStr.end();

        while (forwardIterator != endIterator) {
            if (*forwardIterator == '(') {
                requiredRightBrackets += 2;
                leftBracketsCounter += 1;
            } else if (*forwardIterator == ')') {
                if (leftBracketsCounter < 1) {
                    ++insertionsCounter;
                    requiredRightBrackets += 2;
                    ++leftBracketsCounter;
                }
                --requiredRightBrackets;
                if (std::next(forwardIterator) != endIterator && *std::next(forwardIterator) == ')') {
                    forwardIterator = std::next(forwardIterator, 2);
                    --requiredRightBrackets;
                    --leftBracketsCounter;
                    continue;
                } else {
                    ++insertionsCounter;
                    --requiredRightBrackets;
                }
                --leftBracketsCounter;
            }
            ++forwardIterator;
        }

        insertionsCounter += requiredRightBrackets;
        return insertionsCounter;
    }
};

#endif