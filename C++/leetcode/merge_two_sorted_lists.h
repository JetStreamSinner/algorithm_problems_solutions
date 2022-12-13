#pragma once

// https://leetcode.com/problems/merge-two-sorted-lists/description//
// You are given the heads of two sorted linked lists list1 and list2.
// Merge the two lists in a one sorted list. The list should be made by splicing together
// the nodes of the first two lists.
// Return the head of the merged linked list.
//
// Example 1:
// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]
//
// Example 2:
// Input: list1 = [], list2 = []
// Output: []
//
// Example 3:
// Input: list1 = [], list2 = [0]
// Output: [0]

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr && l2 == nullptr)
            return nullptr;
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;

        auto * result = new ListNode(0);
        auto * current = result;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1 != nullptr && l1->val <= l2->val) {
                current->next = l1;
                l1 = l1->next;
                current = current->next;
            } else if (l2 != nullptr && l2->val < l1->val) {
                current->next = l2;
                l2 = l2->next;
                current = current->next;
            }
        }

        auto * tail = l1 == nullptr ? l2 : l1;
        current->next = tail;

        return result->next;
    }
};
