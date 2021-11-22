#include <iostream>
#include "utils/pretty_print.h"
#include "combination_sum.h"

template<typename T>
void checkTestCase(const T &received, const T &expected, const std::string &description)
{
    std::cout << "[Status: ";
    if (expected == received)
        std::cout << "Success] ";
    else
        std::cout << "Failed] ";
    std::cout << "[Expected: " << expected << ". Received: " << received << "] ";
    std::cout << "[Description: " << description << "]" << std::endl;
}

int main(int argc, char * argv[])
{
    auto test_input_candidates1 = std::vector<int>{2, 3, 6, 7};
    auto test_input_target1 = 7;
    auto expected_output1 = std::vector<std::vector<int>>{{2, 2, 3}, {7}};
    auto received_output1 = Solution().combinationSum(test_input_candidates1, test_input_target1);
    checkTestCase(received_output1, expected_output1, "Test case 1");

    auto test_input_candidates2 = std::vector<int>{2, 3, 5};
    auto test_input_target2 = 8;
    auto expected_output2 = std::vector<std::vector<int>>{{2, 2, 2, 2}, {2, 3, 3}, {3,5}};
    auto received_output2 = Solution().combinationSum(test_input_candidates2, test_input_target2);
    checkTestCase(received_output2, expected_output2, "Test case 2");

    auto test_input_candidates3 = std::vector<int>{2};
    auto test_input_target3 = 1;
    auto expected_output3 = std::vector<std::vector<int>>{};
    auto received_output3 = Solution().combinationSum(test_input_candidates3, test_input_target3);
    checkTestCase(received_output3, expected_output3, "Test case 3");

    auto test_input_candidates4 = std::vector<int>{1};
    auto test_input_target4 = 1;
    auto expected_output4 = std::vector<std::vector<int>>{{1}};
    auto received_output4 = Solution().combinationSum(test_input_candidates4, test_input_target4);
    checkTestCase(received_output4, expected_output4, "Test case 4");

    auto test_input_candidates5 = {1};
    auto test_input_target5 = 2;
    auto expected_output5 = std::vector<std::vector<int>>{{1, 1}};
    auto received_output5 = Solution().combinationSum(test_input_candidates5, test_input_target5);
    checkTestCase(received_output5, expected_output5, "Test case 5");

    return 0;
}