#pragma once

// https://leetcode.com/problems/intersection-of-two-linked-lists/
// Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect.
// If the two linked lists have no intersection at all, return null.
// For example, the following two linked lists begin to intersect at node c1:
// The test cases are generated such that there are no cycles anywhere in the entire linked structure.
// Note that the linked lists must retain their original structure after the function returns.

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        std::unordered_set<ListNode*> cache;
        ListNode * first = headA;
        while (first) {
            cache.insert(first);
            first = first->next;
        }

        ListNode * second = headB;
        while (second) {
            if (cache.find(second) != cache.end()) {
                return second;
            }
            second = second->next;
        }
        return nullptr;
    }
};