#include <iostream>
#include <string>
#include <csignal>
#include <thread>
#include "utils/pretty_print.h"
#include "leetcode/valid_mountain_array.h"
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

    std::vector<int> arr_1 = {2, 1};
    checkTestCase(Solution().validMountain(arr_1), false, "Case 1");
    std::vector<int> arr_2 = {3, 5, 5};
    checkTestCase(Solution().validMountain(arr_2), false, "Case 2");
    std::vector<int> arr_3 = {0, 3, 2, 1};
    checkTestCase(Solution().validMountain(arr_3), true, "Case 3");
    return 0;
}