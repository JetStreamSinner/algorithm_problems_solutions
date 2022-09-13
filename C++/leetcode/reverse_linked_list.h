#pragma once

// https://leetcode.com/problems/reverse-linked-list/
// Given the head of a singly linked list, reverse the list, and return the reversed list.

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        if (!head) {
            return nullptr;
        }

        ListNode * fake = new ListNode(0);
        fake->next = head;

        ListNode * current_node = head;
        ListNode * next_node = head->next;
        ListNode * previous_node = fake;

        while (next_node) {
            ListNode * temp_node = next_node->next;
            current_node->next = previous_node;
            next_node->next = current_node;

            previous_node = current_node;
            current_node = next_node;
            next_node = temp_node;
        }

        delete fake;
        head->next = nullptr;

        return current_node;
    }
};