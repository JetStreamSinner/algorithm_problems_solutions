#include <iostream>
#include <string>
#include <csignal>
#include <thread>
#include "utils/pretty_print.h"
#include "leetcode/check_if_n_and_its_double_exist.h"
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

    std::vector<int> source_1 = {10, 2, 5, 3};
    checkTestCase(Solution().checkIfExist(source_1), true, "Case 1");
    std::vector<int> source_2 = {7, 1, 14, 11};
    checkTestCase(Solution().checkIfExist(source_2), true, "Case 2");
    std::vector<int> source_3 = {3, 1, 7, 11};
    checkTestCase(Solution().checkIfExist(source_3), false, "Case 3");

    return 0;
}