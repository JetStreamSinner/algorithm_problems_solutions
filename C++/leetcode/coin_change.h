#pragma once

// https://leetcode.com/problems/coin-change/
// You are given an integer array coins representing coins of different denominations and an integer amount representing
// a total amount of money. Return the fewest number of coins that you need to make up that amount. If that amount of
// money cannot be made up by any combination of the coins, return -1. You may assume that you have an infinite number
// of each kind of coin.

#include <cstdint>
#include <vector>

class Solution {
public:
    int32_t coinChange(const std::vector<int32_t>& coins, int32_t amount) {
        constexpr int32_t maxInteger = std::numeric_limits<int32_t>::max();
        std::vector<int32_t> cache(amount + 1);

        for (int32_t index = 1; index <= amount; ++index) {
            int32_t minCoins = maxInteger;

            for (int32_t coin : coins) {
                if (index - coin >= 0) {
                    int32_t currCoins = cache.at(index - coin) + 1;
                    if (currCoins < minCoins) {
                        minCoins = currCoins;
                    }
                }
            }
            cache.at(index) = minCoins;
        }
        return std::max(-1, cache.at(amount));
    }
};