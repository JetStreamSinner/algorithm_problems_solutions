#pragma once

#include <cstdlib>

// https://leetcode.com/problems/unique-paths/
// There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]).
// The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
// Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.
// The test cases are generated so that the answer will be less than or equal to 2 * 109.

struct PairHash {
public:
    template<typename T1, typename T2>
    int32_t operator()(const std::pair<T1, T2> &pair) const {
        return std::hash<T1>{}(pair.first) ^ std::hash<T2>{}(pair.second);
    }
};

template<typename T>
struct SizeComparator {
    bool operator()(const T &left, const T &right) const {
        return (left.first == right.first && left.second == right.second) ||
               (left.first == right.second && left.second == right.first);
    }
};

class Solution {
public:
    using GridSize = std::pair<int32_t, int32_t>;

    int32_t uniquePaths(int32_t m, int32_t n) {
        std::unordered_map<std::pair<int32_t, int32_t>, int32_t, PairHash, SizeComparator<std::pair<int32_t, int32_t>>> memo;
        return uniquePathsImpl(m, n, memo);
    }

private:
    int32_t uniquePathsImpl(int32_t m, int32_t n,
                            std::unordered_map<std::pair<int32_t, int32_t>, int32_t, PairHash, SizeComparator<std::pair<int32_t, int32_t>>> &memo) {

        if (memo.contains({m, n})) {
            return memo.at({m, n});
        }

        if (m == 0 || n == 0) {
            return 0;
        }
        if (m == 1 || n == 1) {
            return 1;
        }
        memo[{m, n}] = uniquePathsImpl(m - 1, n, memo) + uniquePathsImpl(m, n - 1, memo);
        return memo.at({m, n});
    }
};
