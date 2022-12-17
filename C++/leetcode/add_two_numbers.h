#pragma once

// https://leetcode.com/problems/add-two-numbers/description/
// You are given two non-empty linked lists representing two non-negative integers.
// The digits are stored in reverse order, and each of their nodes contains a single digit.
// Add the two numbers and return the sum as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * sentinel = new ListNode(-1);
        ListNode * forwarder = sentinel;

        int32_t remainder = 0;
        while (l1 || l2) {
            int32_t first_term = l1 ? l1->val : 0;
            int32_t second_term = l2 ? l2->val : 0;
            int32_t next_digit_val = first_term + second_term + remainder;
            remainder = next_digit_val / 10;
            ListNode * digit_node = new ListNode(next_digit_val % 10);
            forwarder->next = digit_node;

            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
            forwarder = forwarder->next;
        }

        if (remainder) {
            forwarder->next = new ListNode(remainder);
        }

        forwarder = sentinel;
        sentinel = sentinel->next;
        delete forwarder;

        return sentinel;
    }
};
