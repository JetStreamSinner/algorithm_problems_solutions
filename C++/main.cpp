#include <iostream>
#include <string>
#include <thread>
#include "utils/pretty_print.h"
#include "leetcode/integer_to_roman.h"


template<typename T, typename U>
void checkTestCase(const T &received, const U &expected, const std::string &description="") {
    if constexpr (std::is_same_v<bool, T>) {
        std::cerr << std::boolalpha;
    }

    std::cerr << "[Status: ";
    if (expected == received)
        std::cerr << "Success] ";
    else
        std::cerr << "Failed] ";
    std::cerr << "[ Expected |" << expected << "| Received |" << received << "| ]";
    std::cerr << "[Description: " << description << "]" << std::endl;
}

void segfaultHandler(int signum) {
    std::cerr << "Received SEGFAULT while running test case" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(5));
    exit(signum);
}


int main(int argc, char *argv[]) {
    const auto test_input_1 = 3;
    const auto expected_1 = "III";
    checkTestCase(Solution().intToRoman(test_input_1), expected_1, "Three");

    const auto test_input_2 = 58;
    const auto expected_2 = "LVIII";
    checkTestCase(Solution().intToRoman(test_input_2), expected_2, "Fifteen eight");

    const auto test_input_3 = 1994;
    const auto expected_3 = "MCMXCIV";
    checkTestCase(Solution().intToRoman(test_input_3), expected_3, "Ninth nineteen four");

    const auto test_input_4 = 1;
    const auto expected_4 = "I";
    checkTestCase(Solution().intToRoman(test_input_4), expected_4, "One");

    const auto test_input_5 = 2;
    const auto expected_5 = "II";
    checkTestCase(Solution().intToRoman(test_input_5), expected_5, "Two");
    return 0;
}