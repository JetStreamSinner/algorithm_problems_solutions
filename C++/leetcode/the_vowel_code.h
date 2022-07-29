#pragma once
// https://www.codewars.com/kata/53697be005f803751e0015aa
// Step 1: Create a function called encode() to replace all the lowercase vowels in a given string with numbers according to the following pattern:
// a -> 1
// e -> 2
// i -> 3
// o -> 4
// u -> 5
//For example, encode("hello") would return "h2ll4". There is no need to worry about uppercase vowels in this kata.
//Step 2: Now create a function called decode() to turn the numbers back into vowels according to the same pattern shown above.
//For example, decode("h3 th2r2") would return "hi there".
//For the sake of simplicity, you can assume that any numbers passed into the function will correspond to vowels.

#include <string>
#include <unordered_map>

std::unordered_map<char, char> replacements = {
        {'a', 1},
        {'e', 2},
        {'i', 3},
        {'o', 4},
        {'u', 5},
        {1, 'a'},
        {2, 'e'},
        {3, 'i'},
        {4, 'o'},
        {5, 'u'}
};

class Solution {
public:
    std::string encode(const std::string &str) {
        return impl(str);
    }

    std::string decode(const std::string &str) {
        return impl(str);
    }
private:

    void add_replacements(std::string& str, const std::unordered_map<char, char>& repl) {
        std::for_each(str.begin(), str.end(), [&repl](char& ch) {
            if (repl.find(ch) != repl.end()) {
                ch = repl.at(ch);
            }
        });
    }

    std::string impl(const std::string& str) {
        std::string out = str;
        add_replacements(out, replacements);
        return std::move(out);
    }
};