#pragma once

#include <vector>
#include <cassert>

class Solution {
public:

    int32_t maxSquareForIndex(const std::vector<std::vector<bool>>& matrix, int32_t rowIndex, int32_t columnIndex) {
        const std::size_t rowCount = matrix.size();
        const std::size_t columnCount = matrix.at(0).size();

        int32_t maxRow = 0;
        for (int32_t i = rowIndex; i < columnCount && matrix.at(rowIndex).at(i); ++i) {
            maxRow++;
        }

        int32_t maxColumn = 0;
        for (int32_t j = columnIndex; j < rowCount && matrix.at(j).at(columnIndex); ++j) {
            maxColumn++;
        }

        int32_t maxDiag = 0;

        for (int32_t i = rowIndex, j = columnIndex; i < rowCount && j < columnCount && matrix.at(i).at(j); ++i, ++j) {
            maxDiag++;
        }

        return std::min(std::min(maxColumn, maxRow), maxDiag);
    }

    int32_t squareSubmatrix(const std::vector<std::vector<bool>>& matrix) {
        assert(matrix.size() > 0);
        assert(matrix.at(0).size() > 0);


        int32_t maxSquare = std::numeric_limits<int32_t>::min();
        const std::size_t rowCount = matrix.size();
        const std::size_t columnCount = matrix.at(0).size();

        for (int32_t i = 0; i < rowCount; ++i) {
            for (int32_t j = 0; j < columnCount; ++j) {
                int32_t currentMaxSquare = maxSquareForIndex(matrix, i, j);
                if (currentMaxSquare > maxSquare) {
                    maxSquare = currentMaxSquare;
                }
            }
        }

        return maxSquare;
    }
};