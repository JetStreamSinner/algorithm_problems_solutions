#pragma once
#include <vector>

// Reference: https://leetcode.com/problems/word-search/
// Given an m x n grid of characters board and a string word, return true if word exists in the grid.
// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are
// horizontally or vertically neighboring. The same letter cell may not be used more than once.

struct Index
{
    int rowIndex;
    int columnIndex;
};

class Solution {
public:

    bool wordFind(std::vector<std::vector<char>> &board, const Index &index, std::string &currentWord, const std::string &targetWord)
    {
        const auto rowCount = board.size();
        const auto columnCount = board.at(0).size();
        char currentItem = ' ';

        if (index.rowIndex >= 0 && index.rowIndex < rowCount && index.columnIndex >=0 && index.columnIndex < columnCount) {
            currentItem = board.at(index.rowIndex).at(index.columnIndex);
            if (currentItem == '_')
                return false;
        } else {
            return false;
        }

        auto tempWord = currentWord + currentItem;

        if (currentItem != targetWord.at(tempWord.size() - 1))
            return false;

        if (tempWord == targetWord)
            return true;

        bool leftState = false;
        bool rightState = false;
        bool bottomState = false;
        bool upState = false;


        board.at(index.rowIndex).at(index.columnIndex) = '_';

        Index upIndex{index.rowIndex - 1, index.columnIndex};
        upState = wordFind(board, upIndex, tempWord, targetWord);
        if (upState)
            return true;

        Index bottomIndex{index.rowIndex + 1, index.columnIndex};
        bottomState = wordFind(board, bottomIndex, tempWord, targetWord);
        if (bottomState)
            return true;

        Index leftIndex{index.rowIndex, index.columnIndex - 1};
        leftState = wordFind(board, leftIndex, tempWord, targetWord);
        if (leftState)
            return true;

        Index rightIndex{index.rowIndex, index.columnIndex + 1};
        rightState = wordFind(board, rightIndex, tempWord, targetWord);
        if (rightState)
            return true;

        board.at(index.rowIndex).at(index.columnIndex) = currentItem;

        return false;

    }

    bool exist(std::vector<std::vector<char>>& board, const std::string& word)
    {
        const auto rowCount = board.size();
        const auto columnCount = board.at(0).size();

        for (auto rowIndex = 0; rowIndex < rowCount; ++rowIndex) {
            for (auto columnIndex = 0; columnIndex < columnCount; ++columnIndex) {
                Index startIndex{rowIndex, columnIndex};
                std::string tempWord;
                if (wordFind(board, startIndex, tempWord, word))
                    return true;
            }
        }
        return false;
    }
};