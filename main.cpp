#include <iostream>
#include <string>
#include <csignal>
#include <thread>
#include "utils/pretty_print.h"

#include "sberfight/task_4.h"

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

    std::vector<int> test_case_1 = {0, 2, 4, 1, 6, 2};
    checkTestCase(Solution().getResult(test_case_1), true, "Sample test case 1");

    std::vector<int> test_case_2 = {2, -1, 0, 2};
    checkTestCase(Solution().getResult(test_case_2), true, "Sample test case 2");


    std::vector<int> test_case_3 = {-2, -1, -3, -2};
    checkTestCase(Solution().getResult(test_case_3), false, "All fences are negative");

    std::vector<int> test_case_4 = {0, 0, 0, 0};
    checkTestCase(Solution().getResult(test_case_4), false, "All fences are null");

    std::vector<int> test_case_5 = {1, 1, 1, 1};
    checkTestCase(Solution().getResult(test_case_5), true, "All fences are one");

    std::vector<int> test_case_6 = {1};
    checkTestCase(Solution().getResult(test_case_6), true, "One fence with value equal size");

    std::vector<int> test_case_7 = {2};
    checkTestCase(Solution().getResult(test_case_7), false, "One fence with value greater than size");


    std::vector<int> test_case_8 = {15, -15, -15, 15, 5};
    checkTestCase(Solution().getResult(test_case_8), true, "Sum of all items equal zero");


    std::vector<int> test_case_9 = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2} ;
    checkTestCase(Solution().getResult(test_case_9), false, "Sum of all items equal target");


    return 0;
}