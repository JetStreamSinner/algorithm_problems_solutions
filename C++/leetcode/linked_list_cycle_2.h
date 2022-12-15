#pragma once

// https://leetcode.com/problems/linked-list-cycle-ii/description/?envType=study-plan&id=level-1
// Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
// There is a cycle in a linked list if there is some node in the list that can be reached again by
// continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's
// next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.
// Do not modify the linked list.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    bool hasCycle(ListNode *&fast_pointer, ListNode *&slow_pointer) {
        while (fast_pointer && fast_pointer->next) {
            fast_pointer = fast_pointer->next->next;
            slow_pointer = slow_pointer->next;
            if (fast_pointer == slow_pointer) {

                return true;
            }
        }
        return false;
    }

    ListNode *twoPointersImpl(ListNode *head) {
        if (!head || !head->next) {
            return nullptr;
        }

        auto *slow_pointer = head;
        auto *fast_pointer = head;

        const bool without_cycle = !hasCycle(fast_pointer, slow_pointer);

        if (without_cycle) {
            return nullptr;
        }

        fast_pointer = head;
        while (fast_pointer != slow_pointer) {
            fast_pointer = fast_pointer->next;
            slow_pointer = slow_pointer->next;
        }


        return fast_pointer;
    }

    ListNode *hash_map_impl(ListNode *head) {
        std::unordered_set < ListNode * > nodes;

        auto *forwarder = head;
        while (forwarder) {
            if (nodes.find(forwarder) != nodes.end()) {
                return forwarder;
            }
            nodes.insert(forwarder);
            forwarder = forwarder->next;
        }
        return nullptr;
    }

    ListNode *detectCycle(ListNode *head) {
        return twoPointersImpl(head);
    }
};