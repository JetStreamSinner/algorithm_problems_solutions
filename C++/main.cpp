#include <iostream>
#include <string>
#include <thread>
#include "utils/pretty_print.h"
#include "leetcode/plus_one.h"


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
    std::vector<int> input_1 = {1, 2, 3};
    std::vector<int> expected_1 = {1, 2, 4};
    checkTestCase(Solution().plusOne(input_1), expected_1, "Test 1");

    std::vector<int> input_2 = {4, 3, 2, 1};
    std::vector<int> expected_2 = {4, 3, 2, 2};
    checkTestCase(Solution().plusOne(input_2), expected_2, "Test 2");

    std::vector<int> input_3 = {9};
    std::vector<int> expected_3 = {1, 0};
    checkTestCase(Solution().plusOne(input_3), expected_3, "Test 3");
    return 0;
}