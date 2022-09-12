#pragma once

#include <string>
#include <sstream>

class Solution {
public:
    int lengthOfLastWord(const std::string& s) {
        std::stringstream tokenizer(s);
        std::string last_word;
        while (!tokenizer.eof()) {
            tokenizer >> last_word;
        }
        return last_word.size();
    }
};