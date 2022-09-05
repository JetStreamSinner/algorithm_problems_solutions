#include <iostream>
#include <string>
#include <thread>
#include "utils/pretty_print.h"
#include "leetcode/longest_common_prefix.h"


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
    const std::vector<std::string> test_input_1 = { "flower", "flow", "flight" };
    const std::string test_expect_1 = "fl";
    checkTestCase(Solution().longestCommonPrefix(test_input_1), test_expect_1, "Test 1");

    const std::vector<std::string> test_input_2 = { "dog", "racecar", "car" };
    const std::string test_expect_2 = "";
    checkTestCase(Solution().longestCommonPrefix(test_input_2), test_expect_2, "Test 2");
    return 0;
}