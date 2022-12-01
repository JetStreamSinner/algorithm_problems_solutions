#pragma once
// Write a function that reverses a string. The input string is given as an array of characters s.
// You must do this by modifying the input array in-place with O(1) extra memory.

class Solution {
public:

    void manualApproach(std::vector<char>& s) {
        auto forwarder = s.begin();
        auto backwarder = std::prev(s.end());

        while (forwarder < backwarder) {
            std::swap(*forwarder, *backwarder);
            forwarder = std::next(forwarder);
            backwarder = std::prev(backwarder);
        }
    }

    void stlApproach(std::vector<char>& s) {
        std::reverse(s.begin(), s.end());
    }

    void reverseString(std::vector<char>& s) {
        stlApproach(s);
    }
};
