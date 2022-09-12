#include <iostream>
#include <string>
#include <thread>
#include "utils/pretty_print.h"
#include "leetcode/length_of_last_word.h"


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
    std::string input_1 = "Hello World";
    int expected_1 = 5;
    checkTestCase(Solution().lengthOfLastWord(input_1), expected_1, "Test 1");

    std::string input_2 = "   fly me   to   the moon  ";
    int expected_2 = 4;
    checkTestCase(Solution().lengthOfLastWord(input_2), expected_2, "Test 2");

    std::string input_3 = "luffy is still joyboy";
    int expected_3 = 6;
    checkTestCase(Solution().lengthOfLastWord(input_3), expected_3, "Test 3");
    return 0;
}