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
        if (head == nullptr)
            return false;

        std::unordered_set<ListNode*> nodesChecker;

        auto * forwarder = head;
        while (forwarder != nullptr) {
            if (nodesChecker.contains(forwarder))
                return true;
            else {
                nodesChecker.insert(forwarder);
                forwarder = forwarder->next;
            }
        }
        return false;
    }
};

#endif