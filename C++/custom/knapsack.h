#pragma once

#include <vector>
#include <cstdint>

struct Item {
    int32_t weight;
    int32_t value;
};

class Solution {
public:
    using DynamicCache = std::unordered_map<int32_t, std::unordered_map<int32_t, int32_t>>;

    int32_t knapsack(std::vector<Item> &items, int32_t w) {

        DynamicCache cache;

        return knapsack(items, w, 0, cache);
    }

    int32_t knapsack(std::vector<Item> &items, int w, int i, DynamicCache &cache) {
        if (i == items.size()) {
            return 0;
        }

        if (!cache.contains(i)) {
            cache[i] = {};
        }

        if (cache.at(i).contains(w)) {
            return cache.at(i).at(w);
        }

        int32_t toReturn = 0;

        if (w - items.at(i).weight < 0) {
            toReturn = knapsack(items, w, i + 1, cache);
        } else {
            toReturn = std::max(knapsack(items, w - items.at(i).weight, i + 1, cache) + items.at(i).value,
                    knapsack(items, w, i + 1, cache));
        }

        cache.at(i)[w] = toReturn;
        return toReturn;
    }

};
