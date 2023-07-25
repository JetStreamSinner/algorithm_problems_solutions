#include <iostream>
#include <string>
#include <thread>
#include <csignal>
#include "utils/pretty_print.h"
#include "leetcode/longest_substring_without_repeating_characters.h"


template<typename T, typename U>
void checkTestCase(const T &received, const U &expected, const std::string &description = "") {
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
    signal(SIGSEGV, segfaultHandler);

    const std::string input_1 = "abcabcbb";
    const int32_t expect_1 = 3;
    checkTestCase(Solution().lengthOfLongestSubstring(input_1), expect_1, "Test case 1");

    const std::string input_2 = "bbbbb";
    const int32_t expect_2 = 1;
    checkTestCase(Solution().lengthOfLongestSubstring(input_2), expect_2, "Test case 2");

    const std::string input_3 = "pwwkew";
    const int32_t expect_3 = 3;
    checkTestCase(Solution().lengthOfLongestSubstring(input_3), expect_3, "Test case 3");

    const std::string input_4 = "dvdf";
    const int32_t expect_4 = 3;
    checkTestCase(Solution().lengthOfLongestSubstring(input_4), expect_4, "Test case 4");

    return 0;
}