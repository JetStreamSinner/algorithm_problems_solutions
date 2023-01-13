#include <iostream>
#include <string>
#include <thread>
#include <csignal>
#include "utils/pretty_print.h"
#include "leetcode/jump_game_2.h"


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
    std::vector<int32_t> source_1 = {2, 3, 1, 1, 4};
    int32_t expected_1 = 2;
    checkTestCase(Solution().jump(source_1), expected_1, "Test case 1");

    std::vector<int32_t> source_2 = {2, 3, 0, 1, 4};
    int32_t expected_2 = 2;
    checkTestCase(Solution().jump(source_2), expected_2, "Test case 2");
    return 0;
}