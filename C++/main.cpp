#include <iostream>
#include <string>
#include <csignal>
#include <thread>
#include "utils/pretty_print.h"
#include "leetcode/remove_element.h"
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
    std::cerr << "[Expected |" << expected << "| Received |" << received << "| ]";
    std::cerr << "[Description: " << description << "]" << std::endl;
}

void segfaultHandler(int signum) {
    std::cerr << "Received SEGFAULT while running test case" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(5));
    exit(signum);
}

int main(int argc, char *argv[]) {
    signal(SIGSEGV, segfaultHandler);

    std::vector<int> input_vector_1 = { 3, 2, 2, 3 };
    std::vector<int> expected_vector_1 = { 2, 2 };
    const int remove_val_1 = 3;
    const int expected_val_1 = 2;
    checkTestCase(Solution().removeElement(input_vector_1, remove_val_1), expected_val_1, "General test case 1");
    assert(input_vector_1 == expected_vector_1);

    std::vector<int> input_vector_2 = { 0, 1, 2, 2, 3, 0, 4, 2 };
    std::vector<int> expected_vector_2 = { 0, 1, 4, 0, 3 };
    const int remove_val_2 = 2;
    const int expected_val_2 = 5;
    checkTestCase(Solution().removeElement(input_vector_2, remove_val_2), expected_val_2, "General test case 2");
    assert(input_vector_2 == expected_vector_2);


    return 0;
}