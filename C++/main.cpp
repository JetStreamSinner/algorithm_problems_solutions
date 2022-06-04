#include <iostream>
#include <string>
#include <csignal>
#include <thread>
#include "utils/pretty_print.h"


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
    signal(SIGSEGV, segfaultHandler);

    std::vector<int> input_1 = {-4, -1, 0, 3, 10};
    std::vector<int> output_1 = {0, 1, 9, 16, 100};
    checkTestCase(Solution().sortedSquares(input_1), output_1, "Case 1");

    std::vector<int> input_2 = {-7, -3, 2, 3, 11};
    std::vector<int> output_2 = {4, 9, 9, 49, 121};
    checkTestCase(Solution().sortedSquares(input_2), output_2, "Case 2");

    return 0;
}