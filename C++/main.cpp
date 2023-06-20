#include <iostream>
#include <string>
#include <thread>
#include <csignal>
#include "utils/pretty_print.h"
#include "leetcode/unique_paths.h"


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

    int32_t m1 = 3;
    int32_t n1 = 7;
    int32_t expected1 = 28;

    checkTestCase(Solution().uniquePaths(m1, n1), expected1, "Test case 1");

    int32_t m2 = 3;
    int32_t n2 = 2;
    int32_t expected2 = 3;

    checkTestCase(Solution().uniquePaths(m2, n2), expected2, "Test case 2");

    int32_t m3 = 16;
    int32_t n3 = 16;
    int32_t expected3 = 155117520;

    checkTestCase(Solution().uniquePaths(m3, n3), expected3, "Test case 3");

    return 0;
}