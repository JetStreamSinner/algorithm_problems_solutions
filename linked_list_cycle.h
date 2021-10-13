#ifndef LINKED_LIST_CYCLE
#define LINKED_LIST_CYCLE
#include <unordered_set>

struct ListNode
{
    int val;
    ListNode * next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    bool hasCycle(ListNode * head) const
    {
        return false;
    }
};

#endif