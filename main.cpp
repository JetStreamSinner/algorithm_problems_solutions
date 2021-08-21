#include <iostream>
#include "balance_parentheses.h"

template<typename T>
void checkTestCase(const T &received, const T &expected, const std::string &description)
{
    std::cout << "[Status: ";
    if (expected == received)
        std::cout << "Success] ";
    else
        std::cout << "Failed] ";
    std::cout << "[Expected: " << expected << ". Received: " << received << "] ";
    std::cout << "[Description: " << description << "]" << std::endl;
}

int main(int argc, char * argv[])
{
    checkTestCase(BalanceParentheses().minInsertions(")))))))"), 5, ")))))))");
    checkTestCase(BalanceParentheses().minInsertions("(((((("), 12, "((((((");
    checkTestCase(BalanceParentheses().minInsertions("(()))"), 1, "(()))");
    checkTestCase(BalanceParentheses().minInsertions("())"), 0, "())");
    checkTestCase(BalanceParentheses().minInsertions("))())("), 3, "))())(");
    return 0;
}