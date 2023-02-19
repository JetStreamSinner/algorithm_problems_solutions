#include <iostream>
#include <string>
#include <thread>
#include <csignal>
#include "utils/pretty_print.h"
#include "leetcode/minimum_suffix_flips.h"


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

    std::string input_1 = "10111";
    int32_t expected_1 = 3;
    checkTestCase(Solution().minFlips(input_1), expected_1, "Test case 1");

    std::string input_2 = "101";
    int32_t expected_2 = 3;
    checkTestCase(Solution().minFlips(input_2), expected_2, "Test case 2");

    std::string input_3 = "00000";
    int32_t expected_3 = 0;
    checkTestCase(Solution().minFlips(input_3), expected_3, "Test case 3");

    std::string input_4 = "10011111010101000011101010011001000";
    int32_t expected_4 = 4;
    checkTestCase(Solution().minFlips(input_4), expected_4, "Test case 4");

    return 0;
}