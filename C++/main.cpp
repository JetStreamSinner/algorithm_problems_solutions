#include <iostream>
#include <string>
#include <thread>
#include <csignal>
#include "utils/pretty_print.h"
#include "leetcode/island_perimeter.h"


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

    std::vector<std::vector<int32_t>> input_1 = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
    checkTestCase(Solution().islandPerimeter(input_1), 16, "Test 1");
    std::vector<std::vector<int32_t>> input_2 = {{1}};
    checkTestCase(Solution().islandPerimeter(input_1), 16, "Test 2");
    return 0;
}