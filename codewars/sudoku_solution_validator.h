#pragma once

#include <unordered_set>
#include <algorithm>

using SudokuField = std::vector<std::vector<unsigned>>;

class Solution
{
public:
    bool validSolution(const SudokuField& board) const
    {
        // Check if zeroes exists
        auto zeroesValidationPassed = std::all_of(board.begin(), board.end(), [](const auto& row) {
            bool hasZeroes = std::none_of(row.begin(), row.end(), [](const auto value) {
                return value == 0;
            });
            return hasZeroes;
        });

        if (!zeroesValidationPassed) {
            std::cout << "Failed with zeroes" << std::endl;
            return false;
        }

        // Check duplicates in rows
        auto rowsValidationPassed = std::all_of(board.begin(), board.end(), [](const auto& row) {
            std::unordered_set<unsigned> uniques;
            auto rowValid = std::all_of(row.begin(), row.end(), [&](const auto value) {
                const auto hasDuplicate = uniques.find(value) != uniques.end();
                uniques.insert(value);
                return !hasDuplicate;
            });
            return rowValid;
        });

        if (!rowsValidationPassed) {
            std::cout << "Failed with rows" << std::endl;
            return false;
        }

        // Check duplicates in columns
        for (auto columnIndex = 0; columnIndex < columnCount; ++columnIndex) {
            std::unordered_set<unsigned> uniques;
            const auto columnValidationPassed = std::all_of(board.begin(), board.end(), [&](const auto& row) {
                const auto targetValue = *std::next(row.begin(), columnIndex);
                const auto hasDuplicate = uniques.find(targetValue) != uniques.end();
                uniques.insert(targetValue);
                return !hasDuplicate;
            });
            if (!columnValidationPassed) {
                std::cout << "Failed with columns" << std::endl;
                return false;
            }
        }

        for (auto rowOffset = 0; rowOffset < rowCount; rowOffset += 3) {
            for (auto columnOffset = 0; columnOffset < columnCount; columnOffset += 3) {

                const auto leftTop = board.at(rowOffset).at(columnOffset);
                const auto left = board.at(rowOffset + 1).at(columnOffset);
                const auto leftBottom = board.at(rowOffset + 2).at(columnOffset);

                const auto middleTop = board.at(rowOffset).at(columnOffset + 1);
                const auto middle = board.at(rowOffset + 1).at(columnOffset + 1);
                const auto middleBottom = board.at(rowOffset + 2).at(columnOffset + 1);


                const auto rightTop = board.at(rowOffset).at(columnOffset + 2);
                const auto right = board.at(rowOffset + 1).at(columnOffset + 2);
                const auto rightBottom = board.at(rowOffset + 2).at(columnOffset + 2);

                std::vector<std::vector<unsigned>> subfield = {{leftTop, middleTop, rightTop},
                                                               {left, middle, right},
                                                               {leftBottom, middleBottom, rightBottom}};
                const auto subfieldValidationPassed = validateSubfield(subfield);
                if (!subfieldValidationPassed) {
                    return false;
                }
            }
        }
        return true;
    }

    bool validateSubfield(const std::vector<std::vector<unsigned>>& subfield) const
    {
        std::unordered_set<unsigned> uniques;
        const auto subfieldValid = std::all_of(subfield.begin(), subfield.end(), [&](const auto &row) {
            const auto rowValid = std::all_of(row.begin(), row.end(), [&](const auto value) {
                const auto hasDuplicate = uniques.find(value) != uniques.end();
                uniques.insert(value);
                return !hasDuplicate;
            });
            return rowValid;
        });
        return subfieldValid;
    }

private:
    static constexpr auto rowCount = 9;
    static constexpr auto columnCount = 9;
    static constexpr auto subfieldCount = 9;
};
