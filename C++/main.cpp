#include <iostream>
#include <string>
#include <csignal>
#include <thread>
#include "utils/pretty_print.h"
#include "leetcode/find_all_numbers_disappeared_in_array.h"


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

    std::vector<int> input_1 = {4, 3, 2, 7, 8, 2, 3, 1};
    std::vector<int> output_1 = {5, 6};
    checkTestCase(Solution().findDisappearedNumbers(input_1), output_1, "Case 1");

    std::vector<int> input_2 = {1, 1};
    std::vector<int> output_2 = {2};
    checkTestCase(Solution().findDisappearedNumbers(input_2), output_2, "Case 2");

    return 0;
}