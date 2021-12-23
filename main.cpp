#include <iostream>
#include <string>
#include "utils/pretty_print.h"
#include "codewars/simple_pig_latin.h"

template<typename T = std::basic_string<char>, typename DescrT>
void checkTestCase(T&& received, T&& expected, DescrT&& description)
{
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
    checkTestCase(std::string(Solution().pig_it("This is my string")), std::string("hisTay siay ymay tringsay"), "Test case 1");
    checkTestCase(std::string(Solution().pig_it("Pig latin is cool")), std::string("igPay atinlay siay oolcay"), "Test case 2");
    checkTestCase(std::string(Solution().pig_it("Acta est fabula")), std::string("ctaAay steay abulafay"), "Test case 3");
    checkTestCase(std::string(Solution().pig_it("Hello world !")), std::string("elloHay orldway !"), "Test case 4");
    return 0;
}