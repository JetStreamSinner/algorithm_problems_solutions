#include <iostream>
#include <string>
#include <thread>
#include "utils/pretty_print.h"
#include "leetcode/binary_watch.h"


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
    int test_input_1 = 1;
    std::vector<std::string> output_1 = { "0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00" };
    checkTestCase(Solution().readBinaryWatch(test_input_1), output_1, "Test case 1");

    int test_input_2 = 9;
    std::vector<std::string> output_2 = {};
    checkTestCase(Solution().readBinaryWatch(test_input_2), output_2, "Empty test case");
    return 0;
}