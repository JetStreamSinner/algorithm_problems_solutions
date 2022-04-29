#include <iostream>
#include <string>
#include <csignal>
#include <thread>
#include "utils/pretty_print.h"
#include "leetcode/subsets_2.h"


template<typename T, typename U>
void checkTestCase(const T &received, const U &expected, const std::string &description) {
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

void segfaultHandler(int signum) {
    std::cerr << "Received SEGFAULT while running test case" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(5));
    exit(signum);
}

int main(int argc, char *argv[]) {
    signal(SIGSEGV, segfaultHandler);

    const std::vector<int> test_input_1 = {1, 2, 2};
    const std::vector<std::vector<int>> expected_output_1 = {{},
                                                             {1},
                                                             {1, 2},
                                                             {1, 2, 2},
                                                             {2},
                                                             {2, 2}};
    checkTestCase(Solution().subsetsWithDup(test_input_1), expected_output_1, "General case");

    const std::vector<int> test_input_2 = {0};
    const std::vector<std::vector<int>> expected_output_2 = {{},
                                                             {0}};
    checkTestCase(Solution().subsetsWithDup(test_input_2), expected_output_2, "One value case");

    const std::vector<int> test_input_3 = {};
    const std::vector<std::vector<int>> expected_output_3 = {{}};
    checkTestCase(Solution().subsetsWithDup(test_input_3), expected_output_3, "Emtpy input case");

    const std::vector<int> test_input_4 = {2, 1, 2};
    const std::vector<std::vector<int>> expected_output_4 = {{},
                                                             {1},
                                                             {1, 2},
                                                             {1, 2, 2},
                                                             {2},
                                                             {2, 2}};
    checkTestCase(Solution().subsetsWithDup(test_input_4), expected_output_4, "General case with diff order");

    const std::vector<int> test_input_5 = {1, 2, 3};
    const std::vector<std::vector<int>> expected_output_5 = {{},
                                                             {1},
                                                             {1, 2},
                                                             {1, 2, 3},
                                                             {1, 3},
                                                             {2},
                                                             {2, 3},
                                                             {3}};

    checkTestCase(Solution().subsetsWithDup(test_input_5), expected_output_5, "General case");

    return 0;
}