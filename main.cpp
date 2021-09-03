#include <iostream>
#include "linked_list_cycle.h"

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


ListNode * generateFirstList()
{
    auto * firstNode = new ListNode(3);
    auto * secondNode = new ListNode(2);
    auto * thirdNode = new ListNode(0);
    auto * fourthNode = new ListNode(-4);

    firstNode->next = secondNode;
    secondNode->next = thirdNode;
    thirdNode->next = fourthNode;
    fourthNode->next = secondNode;

    return firstNode;
}

ListNode * generateSecondList()
{
    auto * firstNode = new ListNode(1);
    auto * secondNode = new ListNode(2);

    firstNode->next = secondNode;
    secondNode->next = firstNode;

    return firstNode;
}

ListNode * generateThirdList()
{
    auto * firstNode = new ListNode(1);
    return firstNode;
}

ListNode * generateFourthList()
{
    auto * firstNode = new ListNode(1);
    auto * secondNode = new ListNode(2);
    auto * thirdNode = new ListNode(3);

    firstNode->next = secondNode;
    secondNode->next = thirdNode;

    return firstNode;
}

ListNode * generateFifthList()
{
    auto * firstNode = new ListNode(1);
    firstNode->next = firstNode;

    return firstNode;
}

int main(int argc, char * argv[])
{
    checkTestCase(Solution().hasCycle(generateFirstList()), true, "Sample test case");
    checkTestCase(Solution().hasCycle(generateSecondList()), true, "Closed at end");
    checkTestCase(Solution().hasCycle(generateThirdList()), false, "One item");
    checkTestCase(Solution().hasCycle(generateFourthList()), false, "No cycle");
    checkTestCase(Solution().hasCycle(generateFifthList()), true, "Cycled on himself");
    return 0;
}