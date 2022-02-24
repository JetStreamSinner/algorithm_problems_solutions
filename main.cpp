#include <iostream>
#include <string>
#include <csignal>
#include <thread>
#include "utils/pretty_print.h"
#include "leetcode/duplicate_zeros.h"


template<typename T, typename U>
void checkTestCase(const T& received, const U& expected, const std::string& description)
{
    if constexpr (std::is_same_v<bool, T>) {
        std::cerr << std::boolalpha;
    }

    std::cerr << "[Status: ";
    if (expected == received)
        std::cerr << "Success] ";
    else
        std::cerr << "Failed] ";
    std::cerr << "[Expected |" << expected << "| Received |" << received << "| ]";
    std::cerr << "[Description: " << description << "]" << std::endl;
}

void segfaultHandler(int signum)
{
    std::cerr << "Received SEGFAULT while running test case" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(5));
    exit(signum);
}

int main(int argc, char * argv[])
{
    signal(SIGSEGV, segfaultHandler);

    std::vector<int> test_case_1 = {1, 0, 2, 3, 0, 4, 5, 0};
    std::vector<int> expected_1 = {1, 0, 0, 2, 3, 0, 0, 4};

    Solution().duplicateZeros(test_case_1);
    checkTestCase(test_case_1, expected_1, "Case 1");

    std::vector<int> test_case_2 = {1, 2, 3};
    std::vector<int> expected_2 = {1, 2, 3};

    Solution().duplicateZeros(test_case_2);
    checkTestCase(test_case_2, expected_2, "Case 2");

    return 0;
}