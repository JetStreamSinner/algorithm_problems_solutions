#pragma once

// https://leetcode.com/problems/island-perimeter/description/
// You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.
// Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).
// The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.
//
// Example 1:
// Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
// Output: 16
// Explanation: The perimeter is the 16 yellow stripes in the image above.
//
// Example 2:
// Input: grid = [[1]]
// Output: 4
//
// Example 3:
// Input: grid = [[1,0]]
// Output: 4


class Solution {
public:

    struct Cell {
        int32_t row_index;
        int32_t column_index;

        Cell(int32_t ri, int32_t ci) : row_index(ri), column_index(ci) {

        }
    };

    using Matrix = std::vector<std::vector<int32_t>>;

    enum CellType {
        Nothing = 2,
        Land = 1,
        Water = 0
    };


    Cell calc_init_cell(Matrix& grid) {
        const std::size_t row_count = grid.size();
        for (std::size_t row_index = 0; row_index < row_count; ++row_index) {
            const auto& row = grid.at(row_index);
            auto target_cell = std::find(row.begin(), row.end(), CellType::Land);
            if (target_cell != row.end()) {
                return Cell(row_index, std::distance(row.begin(), target_cell));
            }
        }
        throw std::runtime_error("Incorrect grid");
    }

    CellType get_cell_type(const Cell& cell, Matrix& grid) {
        const int32_t row_index = cell.row_index;
        const int32_t column_index = cell.column_index;

        const int32_t row_count = grid.size();
        const int32_t column_count = grid.at(0).size();

        if (row_index < 0 || row_index >= row_count ||
            column_index < 0 || column_index >= column_count)
        {
            return CellType::Nothing;
        }
        return static_cast<CellType>(grid.at(row_index).at(column_index));
    }

    int get_perim_for_contigous_cell(CellType cell_type) {
        int32_t result = 0;
        switch (cell_type) {
            // Fallthrough
            case CellType::Nothing:
            case CellType::Water:
                result = 1;
                break;
            case CellType::Land:
                // Do nothing
                break;
        }
        return result;
    }

    int calc_cell_perim(const Cell& cell, Matrix& grid) {
        const CellType cell_type = get_cell_type(cell, grid);
        if (cell_type != CellType::Land) {
            return 0;
        }

        int32_t row_index = cell.row_index;
        int32_t column_index = cell.column_index;

        // Top
        const Cell top_cell(row_index - 1, column_index);
        const CellType top_cell_type = get_cell_type(top_cell, grid);
        // Bottom
        const Cell bottom_cell(row_index + 1, column_index);
        const CellType bottom_cell_type = get_cell_type(bottom_cell, grid);
        // Right
        const Cell right_cell(row_index, column_index + 1);
        const CellType right_cell_type = get_cell_type(right_cell, grid);
        // Left
        const Cell left_cell(row_index, column_index - 1);
        const CellType left_cell_type = get_cell_type(left_cell, grid);


        int32_t cell_perim = 0;
        for (const auto cell_type : {top_cell_type, bottom_cell_type, right_cell_type, left_cell_type}) {
            cell_perim += get_perim_for_contigous_cell(cell_type);
        }
        return cell_perim;
    }

    int islandPerimeter(Matrix& grid) {
        const Cell init_cell = calc_init_cell(grid);
        int perimeter = 0;

        const std::size_t row_count = grid.size();
        const std::size_t column_count = grid.at(0).size();
        for (std::size_t row_index = 0; row_index < row_count; ++row_index) {
            for (std::size_t column_index = 0; column_index < column_count; ++column_index) {
                const Cell cell(row_index, column_index);
                int32_t cell_perim = calc_cell_perim(cell, grid);
                perimeter += cell_perim;
            }
        }
        return perimeter;
    }
};