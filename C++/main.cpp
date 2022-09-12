#include <iostream>
#include <string>
#include <thread>
#include "utils/pretty_print.h"
#include "leetcode/search_insert_position.h"


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
    std::vector<int> arr_1 = {1, 3, 5, 6};
    int target_1 = 5;
    int expected_1 = 2;
    checkTestCase(Solution().searchInsert(arr_1, target_1), expected_1, "Test 1");

    std::vector<int> arr_2 = {1, 3, 5, 6};
    int target_2 = 2;
    int expected_2 = 1;
    checkTestCase(Solution().searchInsert(arr_2, target_2), expected_2, "Test 2");

    std::vector<int> arr_3 = {1, 3, 5, 6};
    int target_3 = 7;
    int expected_3 = 4;
    checkTestCase(Solution().searchInsert(arr_3, target_3), expected_3, "Test 3");
    return 0;
}