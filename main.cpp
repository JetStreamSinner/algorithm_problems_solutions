#include <iostream>
#include <string>
#include "utils/pretty_print.h"

#include "codewars/split_strings.h"

template<typename T>
void checkTestCase(const T& received, const T& expected, const std::string& description)
{
    if constexpr (std::is_same_v<bool, T>) {
        std::cout << std::boolalpha;
    }

    std::cout << "[Status: ";
    if (expected == received)
        std::cout << "Success] ";
    else
        std::cout << "Failed] ";
    std::cout << "[Expected |" << expected << "| Received |" << received << "| ] ";
    std::cout << "[Description: " << description << "]" << std::endl;
}

int main(int argc, char * argv[])
{
    checkTestCase(Solution().splitStrings("abcdef"), {"ab", "cd", "ef"}, "Event length");
    checkTestCase(Solution().splitStrings("HelloWorld"), {"He", "ll", "oW", "or", "ld"}, "Another even length");
    checkTestCase(Solution().splitStrings("abcde"), {"ab", "cd", "e_"}, "Odd length");
    checkTestCase(Solution().splitStrings("LovePizza"), {"Lo", "ve", "Pi", "zz", "a_"}, "Another odd length");
    return 0;
}