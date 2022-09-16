#pragma once

// https://leetcode.com/problems/implement-queue-using-stacks/
// Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support
// all the functions of a normal queue (push, peek, pop, and empty).
// Implement the MyQueue class:
//
// void push(int x) Pushes element x to the back of the queue.
// int pop() Removes the element from the front of the queue and returns it.
// int peek() Returns the element at the front of the queue.
// boolean empty() Returns true if the queue is empty, false otherwise.
//
// Notes:
// You must use only standard operations of a stack, which means only push to top, peek/pop from top, size,
// and is empty operations are valid.
// Depending on your language, the stack may not be supported natively.
// You may simulate a stack using a list or deque (double-ended queue)
// as long as you use only a stack's standard operations.
//
// Example 1:
// Input
// ["MyQueue", "push", "push", "peek", "pop", "empty"]
// [[], [1], [2], [], [], []]
// Output
// [null, null, null, 1, 1, false]
//
// Explanation
// MyQueue myQueue = new MyQueue();
// myQueue.push(1); // queue is: [1]
// myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
// myQueue.peek(); // return 1
// myQueue.pop(); // return 1, queue is [2]
// myQueue.empty(); // return false
//

class MyQueue {
public:
    MyQueue() {

    }

    void push(int x) {
        from_to(_main, _helper, _main.size());
        _main.push(x);
        from_to(_helper, _main, _helper.size());
    }

    int pop() {
        int out = _main.top();
        _main.pop();
        return out;
    }

    int peek() {
        int out = _main.top();
        return out;
    }

    bool empty() {
        return _main.empty();
    }

private:
    std::stack<int> _main;
    std::stack<int> _helper;

    void from_to(std::stack<int> &from, std::stack<int> &to, std::size_t count) {
        for (std::size_t index = 0; index < count; ++index) {
            int temp = from.top();
            from.pop();
            to.push(temp);
        }
    }
};
