#pragma once

// https://leetcode.com/problems/n-queens-ii/
// The n-queens puzzle is the problem of placing n queens on an n x n chessboard
// such that no two queens attack each other.
// Given an integer n, return the number of distinct solutions to the n-queens puzzle.

class Solution
{
public:
    using ChessField = std::vector<std::vector<char>>;
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

    void backtrackNqueen(ChessField& field, int fieldSize, int rowIndex, int queensRemain, int& count) {

        if (queensRemain == 0) {
            count += 1;
            return;
        }

        if (rowIndex >= fieldSize) {
            return;
        }

        for (auto columnIndex = 0; columnIndex < fieldSize; ++columnIndex) {
            if (!underAttack(field, rowIndex, columnIndex)) {
                placeQueen(field, fieldSize, rowIndex, columnIndex);
                backtrackNqueen(field, fieldSize, rowIndex + 1, queensRemain - 1, count);
                removeQueen(field, fieldSize, rowIndex, columnIndex);
            }
        }
    }

    int totalQueens(int n) {
        ChessField field(n, std::vector<char>(n, freeMark));
        int count = 0;
        for (auto rowIndex = 0; rowIndex < n; ++rowIndex) {
            backtrackNqueen(field, n, rowIndex, n, count);
        }
        return count;
    }

    void printHelper(const ChessField& field, int fieldSize) {
        for (auto rowIndex = 0; rowIndex < fieldSize; ++rowIndex) {
            for (auto columnIndex = 0; columnIndex < fieldSize; ++columnIndex) {
                std::cout << field.at(rowIndex).at(columnIndex);
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
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