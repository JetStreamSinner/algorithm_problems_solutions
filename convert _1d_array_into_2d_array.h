#pragma once
#include <vector>

// Convert 1D Array Into 2D Array
// You are given a 0-indexed 1-dimensional (1D) integer array original, and two integers, m and n. You are tasked with creating
// a 2-dimensional (2D) array with m rows and n columns using all the elements from original.
// The elements from indices 0 to n - 1 (inclusive) of original should form the first row of the constructed 2D array,
// the elements from indices n to 2 * n - 1 (inclusive) should form the second row of the constructed 2D array, and so on.
// Return an m x n 2D array constructed according to the above procedure, or an empty 2D array if it is impossible.

class Solution {
public:
    std::vector<std::vector<int>> construct2DArray(std::vector<int>& original, int rowCount, int columnCount)
    {
        const auto originalSize = original.size();
        const auto targetSize = rowCount * columnCount;
        if (originalSize != targetSize)
            return {};
        std::vector<std::vector<int>> result(rowCount, std::vector<int>(columnCount, 0));

        const auto lastRowIterator = result.end();
        auto originalIterator = original.begin();
        for (auto rowIterator = result.begin(); rowIterator != lastRowIterator; ++rowIterator) {
            const auto lastColumnIterator = rowIterator->end();
            for (auto columnIterator = rowIterator->begin(); columnIterator != lastColumnIterator; ++columnIterator, ++originalIterator)
                *columnIterator = *originalIterator;
        }
        return result;
    }
};