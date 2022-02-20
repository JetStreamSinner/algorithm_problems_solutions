#include <iostream>
#include <string>
#include <csignal>
#include <thread>
#include "utils/pretty_print.h"

#include "sberfight/task_3.h"

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

    std::vector<int> test_case_1 = {1, 2, 3, 4};
    checkTestCase(Solution().getResult(test_case_1, 1), 4, "Sample ordered test case");


    std::vector<int> test_case_2 = {1, 2, 3};
    checkTestCase(Solution().getResult(test_case_2, 0), 0, "K is lower than minimal value");


    std::vector<int> test_case_3 = {};
    checkTestCase(Solution().getResult(test_case_3, 10), 0, "Empty input vector with random K");


    std::vector<int> test_case_4 = {};
    checkTestCase(Solution().getResult(test_case_4, 0), 0, "Empty input vector with K = 0");


    std::vector<int> test_case_5 = {10, 5, 9, 1, 3};
    checkTestCase(Solution().getResult(test_case_5, 6), 5, "Sample not ordered test case");


    std::vector<int> test_case_7 = {10, 5, 9, 1, 3};
    checkTestCase(Solution().getResult(test_case_7, 20), test_case_7.size(), "K is greater than all values");


    std::vector<int> test_case_8 = {5, 5, 5, 5, 5};
    checkTestCase(Solution().getResult(test_case_8, 0), 0, "All values equal k is zero");


    std::vector<int> test_case_9 = {5, 5, 5, 5, 5};
    checkTestCase(Solution().getResult(test_case_9, 9), test_case_9.size(), "All values equal k is greater");


    std::vector<int> test_case_10 = {5};
    checkTestCase(Solution().getResult(test_case_10, 7), 1, "One value in list K is greater");


    std::vector<int> test_case_11 = {5};
    checkTestCase(Solution().getResult(test_case_11, 5), 1, "One value in list K is equal");


    std::vector<int> test_case_12 = {5};
    checkTestCase(Solution().getResult(test_case_12, 4), 0, "One value in list K is lesser");


    std::vector<int> test_case_13 = {6, 9, 8, 2};
    checkTestCase(Solution().getResult(test_case_13, 3), 1, "Sample");

    return 0;
}