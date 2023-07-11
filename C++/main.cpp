#include <iostream>
#include <string>
#include <thread>
#include <csignal>
#include "utils/pretty_print.h"
#include "leetcode/target_sum.h"


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

    std::vector<int32_t> arr_1 = {1, 1, 1, 1, 1};
    int32_t target_1 = 3;
    int32_t expected_1 = 5;
    checkTestCase(Solution().findTargetSumWays(arr_1, target_1), expected_1, "Test case 1");

    std::vector<int32_t> arr_2 = {1};
    int32_t target_2 = 1;
    int32_t expected_2 = 1;
    checkTestCase(Solution().findTargetSumWays(arr_2, target_2), expected_2, "Test case 2");

    return 0;
}