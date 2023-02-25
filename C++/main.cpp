#include <iostream>
#include <string>
#include <thread>
#include <csignal>
#include "utils/pretty_print.h"
#include "leetcode/coin_change.h"


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

    std::vector<int32_t> input_coins_1 = {1, 2, 5};
    int32_t input_amount_1 = 11;
    int32_t expected_1 = 3;
    checkTestCase(Solution().coinChange(input_coins_1, input_amount_1), expected_1, "Test case 1");

    std::vector<int32_t> input_coins_2 = {2};
    int32_t input_amount_2 = 3;
    int32_t expected_2 = -1;
    checkTestCase(Solution().coinChange(input_coins_2, input_amount_2), expected_2, "Test case 2");

    std::vector<int32_t> input_coins_3 = {2};
    int32_t input_amount_3 = 3;
    int32_t expected_3 = -1;
    checkTestCase(Solution().coinChange(input_coins_3, input_amount_3), expected_3, "Test case 3");


    // Ones and zeros cases
//    std::vector<std::string> input_1 = {"10","0001","111001","1","0"};
//    int32_t input_m_1 = 5;
//    int32_t input_n_1 = 3;
//    int32_t expected_1 = 4;
//    checkTestCase(Solution().findMaxForm(input_1, input_m_1, input_n_1), expected_1, "Test 1");
//
//    std::vector<std::string> input_2 = {"10","0","1"};
//    int32_t input_m_2 = 1;
//    int32_t input_n_2 = 1;
//    int32_t expected_2 = 2;
//    checkTestCase(Solution().findMaxForm(input_2, input_m_2, input_n_2), expected_2, "Test 2");

    return 0;
}