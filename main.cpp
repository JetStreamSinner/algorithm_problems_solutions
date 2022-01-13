#include <iostream>
#include <string>
#include "utils/pretty_print.h"
#include "codewars/sudoku_solution_validator.h"

template<typename T>
void checkTestCase(const T& received, const T& expected, const std::string& description)
{
    if constexpr (std::is_same_v<bool, T>) {
        std::cout << std::boolalpha;
    }

    std::cout << "[Status: ";
    if (expected == received)
        std::cout << "Success] ";
    else
        std::cout << "Failed] ";
    std::cout << "[Expected |" << expected << "| Received |" << received << "| ] ";
    std::cout << "[Description: " << description << "]" << std::endl;
}

int main(int argc, char * argv[])
{
    std::vector<std::vector<unsigned>> test1 =
                         {{5, 3, 4, 6, 7, 8, 9, 1, 2},
                          {6, 7, 2, 1, 9, 5, 3, 4, 8},
                          {1, 9, 8, 3, 4, 2, 5, 6, 7},
                          {8, 5, 9, 7, 6, 1, 4, 2, 3},
                          {4, 2, 6, 8, 5, 3, 7, 9, 1},
                          {7, 1, 3, 9, 2, 4, 8, 5, 6},
                          {9, 6, 1, 5, 3, 7, 2, 8, 4},
                          {2, 8, 7, 4, 1, 9, 6, 3, 5},
                          {3, 4, 5, 2, 8, 6, 1, 7, 9}};
    checkTestCase(Solution().validSolution(test1), true, "First test case");

    std::vector<std::vector<unsigned>> test2 = {{5, 3, 4, 6, 7, 8, 9, 1, 2},
                                                {6, 7, 2, 1, 9, 0, 3, 4, 8},
                                                {1, 0, 0, 3, 4, 2, 5, 6, 0},
                                                {8, 5, 9, 7, 6, 1, 0, 2, 0},
                                                {4, 2, 6, 8, 5, 3, 7, 9, 1},
                                                {7, 1, 3, 9, 2, 4, 8, 5, 6},
                                                {9, 0, 1, 5, 3, 7, 2, 1, 4},
                                                {2, 8, 7, 4, 1, 9, 6, 3, 5},
                                                {3, 0, 0, 4, 8, 1, 1, 7, 9}};

    checkTestCase(Solution().validSolution(test2), false, "Second test case");
    return 0;
}