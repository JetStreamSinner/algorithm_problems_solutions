#include <iostream>
#include <string>
#include <csignal>
#include <thread>
#include "utils/pretty_print.h"
#include "leetcode/remove_duplicates_from_sorted_array.h"
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

    std::vector<int> nums_1 = {1, 1, 2};
    std::vector<int> output_nums_1 = {1, 2};
    int output_count_1 = 2;
    checkTestCase(Solution().removeDuplicates(nums_1), output_count_1, "Case 1");
    checkTestCase(nums_1, output_nums_1, "Case 1");

    std::vector<int> nums_2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    std::vector<int> output_nums_2 = {0, 1, 2, 3, 4};
    int output_count_2 = 5;
    checkTestCase(Solution().removeDuplicates(nums_2), output_count_2, "Case 2");
    checkTestCase(nums_2, output_nums_2, "Case 1");

    return 0;
}