#pragma once


class Solution
{
public:
    using ChessField = std::vector<std::vector<char>>;
    const char attackMark = '#';
    const char freeMark = 'O';

    bool underAttack(const ChessField& field, int rowIndex, int columnIndex) {
        return field.at(rowIndex).at(columnIndex) == attackMark;
    }

    void placeQueen(ChessField& field, int fieldSize, int rowIndex, int columnIndex) {
        fillPattern(field, fieldSize, rowIndex, columnIndex, attackMark);
    }

    void removeQueen(ChessField& field, int fieldSize, int rowIndex, int columnIndex) {
        fillPattern(field, fieldSize, rowIndex, columnIndex, freeMark);
    }

    void backtrackNqueen(ChessField& field, int fieldSize, int queensRemain, int& count) {

        if (queensRemain == 0) {
            printHelper(field, fieldSize);
            count += 1;
            return;
        }

        for (auto rowIndex = 0; rowIndex < fieldSize; ++rowIndex) {
            for (auto columnIndex = 0; columnIndex < fieldSize; ++columnIndex) {
                if (!underAttack(field, rowIndex, columnIndex)) {
                    placeQueen(field, fieldSize, rowIndex, columnIndex);
                    backtrackNqueen(field, fieldSize, queensRemain - 1, count);
                    removeQueen(field, fieldSize, rowIndex, columnIndex);
                }
            }
        }
    }

    int totalQueens(int n) {
        ChessField field(n, std::vector<char>(n, freeMark));
        const auto queensCount = 4;
        int count = 0;
        backtrackNqueen(field, n, queensCount, count);
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
    void fillPattern(ChessField& field, int fieldSize, int rowIndex, int columnIndex, char fillCharacter) {
        // Mark column
        for (auto rowIt = 0; rowIt < fieldSize; ++rowIt) {
            field.at(rowIt).at(columnIndex) = fillCharacter;
        }

        // Mark row
        for (auto colIt = 0; colIt < fieldSize; ++colIt) {
            field.at(rowIndex).at(colIt) = fillCharacter;
        }

        // TODO Compress this cycles pairs into one using some formula
        // Mark main diag
        for (auto rowIt = rowIndex, colIt = columnIndex; rowIt < fieldSize && colIt < fieldSize; ++rowIt, ++colIt) {
            field.at(rowIt).at(colIt) = fillCharacter;
        }

        for (auto rowIt = rowIndex, colIt = columnIndex; rowIt >= 0 && colIt >= 0; --rowIt, --colIt) {
            field.at(rowIt).at(colIt) = fillCharacter;
        }

        // Mark sub diag
        for (auto rowIt = rowIndex, colIt = columnIndex; rowIt < fieldSize && colIt >= 0; ++rowIt, --colIt) {
            field.at(rowIt).at(colIt) = fillCharacter;
        }

        for (auto rowIt = rowIndex, colIt = columnIndex; rowIt >= 0 && colIt < fieldSize; --rowIt, ++colIt) {
            field.at(rowIt).at(colIt) = fillCharacter;
        }
    }
};