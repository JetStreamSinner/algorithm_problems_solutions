#pragma once

// https://leetcode.com/problems/number-of-islands
// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water),
// return the number of islands.
// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
// You may assume all four edges of the grid are all surrounded by water.

class Solution {
public:
    struct Cell {
        int32_t ri;
        int32_t ci;

        explicit Cell(int32_t r, int32_t c) : ri(r), ci(c) {

        }
    };

    const char visited = 'x';
    const char water = '0';

    bool dfs(std::vector<std::vector<char>>& grid, std::size_t ri, std::size_t ci) {
        if (grid.at(ri).at(ci) == visited || grid.at(ri).at(ci) == water) {
            return false;
        }

        std::stack<Cell> cells;
        const Cell start_cell(ri, ci);
        cells.push(start_cell);

        while (!cells.empty()) {
            const Cell cell = cells.top();
            cells.pop();

            if (cell.ri < 0 || cell.ri >= grid.size() || cell.ci < 0 || cell.ci >= grid.at(0).size()) {
                continue;
            }

            if (grid.at(cell.ri).at(cell.ci) == visited) {
                continue;
            }

            if (grid.at(cell.ri).at(cell.ci) == water) {
                continue;
            }

            grid.at(cell.ri).at(cell.ci) = visited;

            Cell top_cell(cell.ri - 1, cell.ci);
            Cell bottom_cell(cell.ri + 1, cell.ci);
            Cell right_cell(cell.ri, cell.ci + 1);
            Cell left_cell(cell.ri, cell.ci - 1);

            cells.push(top_cell);
            cells.push(bottom_cell);
            cells.push(right_cell);
            cells.push(left_cell);
        }
        return true;
    }

    int32_t numIslands(std::vector<std::vector<char>>& grid) {
        const std::size_t row_size = grid.size();
        const std::size_t column_size = grid.at(0).size();
        const std::size_t cells_count = grid.size() * grid.at(0).size();
        std::size_t island_counter = 0;
        for (std::size_t ri = 0, ci = 0, index = 0; index < cells_count; ++index) {
            const bool found_new_island = dfs(grid, ri, ci);
            island_counter += found_new_island ? 1 : 0;
            if (ci < column_size - 1) {
                ci++;
            } else {
                ci = 0;
                ri++;
            }
        }
        return island_counter;
    }
};
