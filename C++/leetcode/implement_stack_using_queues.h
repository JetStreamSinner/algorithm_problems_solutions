#pragma once

// https://leetcode.com/problems/implement-stack-using-queues/
// Implement a last-in-first-out (LIFO) stack using only two queues.
// The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).
// Implement the MyStack class:
//
// void push(int x) Pushes element x to the top of the stack.
// int pop() Removes the element on the top of the stack and returns it.
// int top() Returns the element on the top of the stack.
// boolean empty() Returns true if the stack is empty, false otherwise.
//
// Notes:
// You must use only standard operations of a queue, which means that only push to back,
// peek/pop from front,
// size and is empty operations are valid.
// Depending on your language, the queue may not be supported natively.
// You may simulate a queue using a list or deque (double-ended queue)
// as long as you use only a queue's standard operations.
//
//
//
// Example 1:
//
// Input
// ["MyStack", "push", "push", "top", "pop", "empty"]
// [[], [1], [2], [], [], []]
// Output
// [null, null, null, 2, 2, false]
//
// Explanation
// MyStack myStack = new MyStack();
// myStack.push(1);
// myStack.push(2);
// myStack.top(); // return 2
// myStack.pop(); // return 2
// myStack.empty(); // return False
//


class MyStack {
public:
    MyStack() {

    }

    void push(int x) {
        while (!_main.empty()) {
            _proxy.push(_main.front());
            _main.pop();
        }
        _main.push(x);
        release_proxy();

    }

    int pop() {
        move_to_proxy_until(1);
        int out = _main.front();
        _main.pop();
        release_proxy();
        return out;
    }

    int top() {
        move_to_proxy_until(1);
        int out = _main.front();
        release_proxy();
        return out;
    }

    bool empty() {
        return _main.empty();
    }

private:
    std::queue<int> _main;
    std::queue<int> _proxy;

    void move_to_proxy_until(int bound) {
        while (!_main.size() > bound) {
            _proxy.push(_main.front());
            _main.pop();
        }
    }

    void release_proxy() {
        while (!_proxy.empty()) {
            _main.push(_proxy.front());
            _proxy.pop();
        }
    }
};
