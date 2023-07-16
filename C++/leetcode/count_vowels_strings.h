#pragma once

// https://leetcode.com/problems/count-sorted-vowel-strings
// Given an integer n, return the number of strings of length n that consist only of vowels (a, e, i, o, u) and are
// lexicographically sorted.
// A string s is lexicographically sorted if for all valid i, s[i] is the same as or comes before s[i+1] in the alphabet.

struct PairHash {
public:
    template<typename T1, typename T2>
    int32_t operator()(const std::pair<T1, T2> &pair) const {
        return std::hash<T1>{}(pair.first) ^ std::hash<T2>{}(pair.second);
    }
};

template<typename T>
struct PairComparator {
    bool operator()(const T &left, const T &right) const {
        return (left.first == right.first && left.second == right.second);
    }
};

using Memo = std::unordered_map<std::pair<int32_t, int32_t>, int32_t, PairHash, PairComparator<std::pair<int32_t, int32_t>>>;

class Solution {
public:
    int32_t countVowelStrings(int32_t n) {
        const std::string vowels = "aeiou";
        const std::size_t vowelsSize = vowels.size();
        int32_t result = 0;
        Memo memo;
        for (int32_t index = 0; index < vowelsSize; ++index) {
            result += dp(n, index, vowels, memo);
        }
        return result;
    }

private:
    int32_t dp(int32_t n, int32_t startIndex, const std::string& source, Memo& memo)
    {
        if (memo.count({n, startIndex})) {
            return memo.at({n, startIndex});
        }

        if (n == 1) {
            return 1;
        }

        int32_t result = 0;
        for (int32_t index = startIndex; index < source.size(); ++index) {
            memo[{n - 1, index}] = dp(n - 1, index, source, memo);
            result += memo.at({n - 1, index});
        }

        memo[{n, startIndex}] = result;
        return memo.at({n, startIndex});
    }
};