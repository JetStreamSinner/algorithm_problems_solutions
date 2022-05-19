#pragma once

#include <vector>
#include <string>

// https://leetcode.com/problems/n-queens/
// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.'
// both indicate a queen and an empty space, respectively.

class Solution
{
public:
    using ChessField = std::vector<std::string>;
    const char attackMark = 'Q';
    const char freeMark = '.';

    bool underAttack(const ChessField& field, int rowIndex, int columnIndex) {
        return !checkIndex(field, field.size(), rowIndex, columnIndex);
    }

    void placeQueen(ChessField& field, int fieldSize, int rowIndex, int columnIndex) {
        field.at(rowIndex).at(columnIndex) = attackMark;
    }

    void removeQueen(ChessField& field, int fieldSize, int rowIndex, int columnIndex) {
        field.at(rowIndex).at(columnIndex) = freeMark;
    }

    void backtrackNqueen(ChessField& field, int fieldSize, int rowIndex, int queensRemain, std::vector<std::vector<std::string>>& result) {

        if (queensRemain == 0) {
            result.push_back(field);
            return;
        }

        if (rowIndex >= fieldSize) {
            return;
        }

        for (auto columnIndex = 0; columnIndex < fieldSize; ++columnIndex) {
            if (!underAttack(field, rowIndex, columnIndex)) {
                placeQueen(field, fieldSize, rowIndex, columnIndex);
                backtrackNqueen(field, fieldSize, rowIndex + 1, queensRemain - 1, result);
                removeQueen(field, fieldSize, rowIndex, columnIndex);
            }
        }
    }

    std::vector<std::vector<std::string>> solveNQueens(int n) {
        ChessField field(n, std::string(n, freeMark));

        std::vector<std::vector<std::string>> result;
        for (auto rowIndex = 0; rowIndex < n; ++rowIndex) {
            backtrackNqueen(field, n, rowIndex, n, result);
        }

        return result;
    }

private:
    bool checkIndex(const ChessField& field, int fieldSize, int rowIndex, int columnIndex) {
        // Mark column
        for (auto rowIt = 0; rowIt < fieldSize; ++rowIt) {
            if (field.at(rowIt).at(columnIndex) == attackMark) {
                return false;
            }
        }

        // Mark row
        for (auto colIt = 0; colIt < fieldSize; ++colIt) {
            if (field.at(rowIndex).at(colIt) == attackMark) {
                return false;
            }
        }

        // TODO Compress this cycles pairs into one using some formula
        // Mark main diag
        for (auto rowIt = rowIndex, colIt = columnIndex; rowIt < fieldSize && colIt < fieldSize; ++rowIt, ++colIt) {
            if (field.at(rowIt).at(colIt) == attackMark) {
                return false;
            }
        }

        for (auto rowIt = rowIndex, colIt = columnIndex; rowIt >= 0 && colIt >= 0; --rowIt, --colIt) {
            if (field.at(rowIt).at(colIt) == attackMark) {
                return false;
            }
        }

        // Mark sub diag
        for (auto rowIt = rowIndex, colIt = columnIndex; rowIt < fieldSize && colIt >= 0; ++rowIt, --colIt) {
            if (field.at(rowIt).at(colIt) == attackMark) {
                return false;
            }
        }

        for (auto rowIt = rowIndex, colIt = columnIndex; rowIt >= 0 && colIt < fieldSize; --rowIt, ++colIt) {
            if (field.at(rowIt).at(colIt) == attackMark) {
                return false;
            }
        }
        return true;
    }
};
