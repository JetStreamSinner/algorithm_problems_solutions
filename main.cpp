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
    return 0;
}