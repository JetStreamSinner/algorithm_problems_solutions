#include <iostream>
#include "find_first_and_last_position.h"

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
    checkTestCase(FindFirstAndLastPosition::searchRange(std::vector<int>({5, 7, 7, 8, 8, 10}), 8), std::vector<int>{3, 4}, "Sample case");
    checkTestCase(FindFirstAndLastPosition::searchRange(std::vector<int>({5, 7, 7, 8, 8, 10}), 6), std::vector<int>{-1, -1}, "Sample case");
    checkTestCase(FindFirstAndLastPosition::searchRange(std::vector<int>({1, 3}), 1), std::vector<int>{0, 0}, "Sample case");
    checkTestCase(FindFirstAndLastPosition::searchRange(std::vector<int>({ 1 }), 1), std::vector<int>{0, 0}, "Sample case");
    checkTestCase(FindFirstAndLastPosition::searchRange(std::vector<int>({}), 0), std::vector<int>{-1, -1}, "Sample case");
    checkTestCase(FindFirstAndLastPosition::searchRange(std::vector<int>({ 1 }), 0), std::vector<int>{-1, -1}, "Sample case");
    checkTestCase(FindFirstAndLastPosition::searchRange(std::vector<int>({ 1, 3 }), 1), std::vector<int>{ 0, 0 }, "Sample case");

    return 0;
}