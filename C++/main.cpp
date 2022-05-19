#include <iostream>
#include <string>
#include <csignal>
#include <thread>
#include "utils/pretty_print.h"
#include "leetcode/n_queens_1.h"
#include <cassert>


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

    const std::vector<std::vector<std::string>> expected_1 = {{".Q..","...Q","Q...","..Q."},
                                                              {"..Q.","Q...","...Q",".Q.."}};
    checkTestCase(Solution().solveNQueens(4), expected_1, "General case");

    const std::vector<std::vector<std::string>> expected_2 = {{"Q"}};
    checkTestCase(Solution().solveNQueens(1), expected_2, "One dim field case");

// target_sum_2_tests
//    std::vector<int> candidates_1 = { 10, 1, 2, 7, 6, 1, 5 };
//    int target_1 = 8;
//    std::vector<std::vector<int>> output_1 = { {1, 1, 6}, {1, 2, 5}, {1, 7}, {2, 6} };
//    checkTestCase(Solution().combinationSum2(candidates_1, target_1), output_1, "General test case 1");
//
//    std::vector<int> candidates_2 = { 2, 5, 2, 1, 2 };
//    int target_2 = 5;
//    std::vector<std::vector<int>> output_2 = { {1, 2, 2}, {5} };
//    checkTestCase(Solution().combinationSum2(candidates_2, target_2), output_2, "General test case 2");

    return 0;
}