#include <iostream>
#include <string>
#include <thread>
#include "utils/pretty_print.h"
#include "leetcode/sqrt_x.h"


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
    int input_1 = 4;
    int expect_1 = 2;
    checkTestCase(Solution().mySqrt(input_1), expect_1, "Test 1");

    int input_2 = 8;
    int expect_2 = 2;
    checkTestCase(Solution().mySqrt(input_2), expect_2, "Test 2");

    return 0;
}