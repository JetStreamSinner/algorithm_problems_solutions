
#ifndef FIND_FIRST_AND_LAST_POSITION_H
#define FIND_FIRST_AND_LAST_POSITION_H

#include <vector>
#include <algorithm>

// Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
// If target is not found in the array, return [-1, -1].
// You must write an algorithm with O(log n) runtime complexity.
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

template<typename T>
bool operator==(std::vector<T> &vec1, const std::vector<T> &vec2)
{
    if (vec1.size() != vec2.size())
        return false;

    auto firstVecIterator = vec1.cbegin();
    auto secondVecIterator = vec2.cbegin();

    const auto firstVecEnd = vec1.cend();

    while (firstVecIterator != firstVecEnd) {
        if (*firstVecIterator != *secondVecIterator)
            return false;
        ++firstVecIterator;
        ++secondVecIterator;
    }
    return true;
}

template<typename T>
std::ostream& operator<<(std::ostream &os, const std::vector<T> &vec)
{
    os << "{ ";
    for (const auto &value : vec)
        os << value << " ";
    os << "}";
    return os;
}

class FindFirstAndLastPosition
{
public:
    template<typename Container>
    static std::vector<int> searchRange(Container &&nums, int target)
    {
        if (nums.empty())
            return { -1, -1 };

        const auto startIterator = nums.begin();
        const auto endIterator = nums.end();

        auto [rangeStartFrom, status] = binarySearch(nums, target);

        if (!status)
            return { -1, -1 };

        auto leftForwarding = rangeStartFrom;
        auto rightForwarding = rangeStartFrom;

        while (leftForwarding != startIterator && *std::prev(leftForwarding) == *rangeStartFrom)
            --leftForwarding;

        while (rightForwarding != std::prev(endIterator) && *std::next(rightForwarding) == *rangeStartFrom)
            ++rightForwarding;

        auto startIndex = static_cast<int>(std::distance(startIterator, leftForwarding));
        auto endIndex = static_cast<int>(std::distance(startIterator, rightForwarding));

        return { startIndex, endIndex };
    }

    using It = std::vector<int>::iterator;
    template<typename Container>
    static std::pair<It, bool> binarySearch(Container &&container, int target)
    {
        return binarySearchImpl(container.begin(), container.end(), target);
    }

    static std::pair<It, bool> binarySearchImpl(It rangeStart, It rangeEnd, int target)
    {
        const auto rangeLength = std::distance(rangeStart, rangeEnd);
        const auto middleItem = std::next(rangeStart, rangeLength / 2);

        if (rangeLength == 1 && *middleItem != target)
            return { It(), false };

        if (*middleItem == target)
            return { middleItem, true };

        if (*middleItem > target)
            return binarySearchImpl(rangeStart, middleItem, target);
        else if (*middleItem < target)
            return binarySearchImpl(middleItem, rangeEnd, target);

        return { It(), false };
    }
};

#endif //FIND_FIRST_AND_LAST_POSITION_H
