#include <iostream>
#include <string>
#include <csignal>
#include <thread>
#include "utils/pretty_print.h"
#include "leetcode/merge_sorted_array.h"


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

    std::vector<int> test_case_1_num_1 = {1, 2, 3, 0, 0, 0};
    std::vector<int> test_case_1_num_2 = {2, 5, 6};
    std::vector<int> test_case_1_expected = {1,2,2,3,5,6};
    const auto test_case_1_m = 3;
    const auto test_case_1_n = 3;
    Solution().merge(test_case_1_num_1, test_case_1_m, test_case_1_num_2, test_case_1_n);
    checkTestCase(test_case_1_num_1, test_case_1_expected, "Sample test case");

    std::vector<int> test_case_2_num_1 = {1};
    std::vector<int> test_case_2_num_2 = {};
    std::vector<int> test_case_2_expected = {1};
    const auto test_case_2_m = 1;
    const auto test_case_2_n = 0;
    Solution().merge(test_case_2_num_1, test_case_2_m, test_case_2_num_2, test_case_2_n);
    checkTestCase(test_case_2_num_1, test_case_2_expected, "Second array are empty");

    std::vector<int> test_case_3_num_1 = {0};
    std::vector<int> test_case_3_num_2 = {1};
    std::vector<int> test_case_3_expected = {1};
    const auto test_case_3_m = 0;
    const auto test_case_3_n = 1;
    Solution().merge(test_case_3_num_1, test_case_3_m, test_case_3_num_2, test_case_3_n);
    checkTestCase(test_case_3_num_1, test_case_3_num_2, "First array are empty");

    std::vector<int> test_case_4_num_1 = {4, 5, 6, 0, 0, 0};
    std::vector<int> test_case_4_num_2 = {1, 2, 3};
    std::vector<int> test_case_4_expected = {1, 2, 3, 4, 5, 6};
    const auto test_case_4_m = 3;
    const auto test_case_4_n = 3;
    Solution().merge(test_case_4_num_1, test_case_4_m, test_case_4_num_2, test_case_4_n);
    checkTestCase(test_case_4_num_1, test_case_4_expected, "First array greater than second");

    std::vector<int> test_case_5_num_1 = {1, 0};
    std::vector<int> test_case_5_num_2 = {2};
    std::vector<int> test_case_5_expected = {1, 2};
    const auto test_case_5_m = 1;
    const auto test_case_5_n = 1;
    Solution().merge(test_case_5_num_1, test_case_5_m, test_case_5_num_2, test_case_5_n);
    checkTestCase(test_case_5_num_1, test_case_5_expected, "First array greater than second");

    return 0;
}