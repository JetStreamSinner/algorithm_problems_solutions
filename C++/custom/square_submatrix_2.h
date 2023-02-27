#pragma once

#include <vector>
#include <cassert>

class Solution {
public:

    int32_t squareSubmatrix(std::vector<std::vector<bool>> &matrix) {
        int32_t max = 0;
        std::vector<std::vector<int32_t>> cache(matrix.size(), std::vector<int32_t>(matrix.at(0).size()));

        for (int32_t i = 0; i < cache.size(); ++i) {
            for (int32_t j = 0; j < cache.at(0).size(); ++j) {

                if (i == 0 || j == 0) {
                    cache.at(i).at(j) = matrix.at(i).at(j) ? 1 : 0;
                } else if (matrix.at(i).at(j)) {
                    cache.at(i).at(j) = std::min(std::min(cache.at(i).at(j - 1), cache.at(i - 1).at(j)),
                                                 cache.at(i - 1).at(j - 1)) + 1;
                }
                if (cache.at(i).at(j) > max) {
                    max = cache.at(i).at(j);
                }
            }
        }
        return max;
    }
};
