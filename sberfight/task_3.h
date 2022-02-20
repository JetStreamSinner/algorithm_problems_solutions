#ifndef BALANCE_PARENTHESES_H
#define BALANCE_PARENTHESES_H

#include <algorithm>
#include <iostream>
#include <vector>

//  Дан массив nums. За одну операцию вы удаляете одно число из массива со значением или k, или меньше k.
//  После каждого удаления k увеличивается на единицу.
//  Определите, сколько элементов массива сможете удалить.

//  На входе:
//  nums - целочисленный массив,  0<length(nums)<=10
//  k - начальное значение числа, которое вы можете удалить из массива

//  На выходе:
//  Integer - количество элементов, которые можно удалить

//  Пример:
//  nums = [1, 2, 3, 4]
//  k = 1
//  getResult(nums, k) = 4
//  k = 1, nums = [*1*, 2, 3, 4] ->
//  k = 2, nums = [*2*, 3, 4] ->
//  k = 3, nums = [*3*, 4] ->
//  k = 4, nums = [*4*] ->
//  k = 5, nums = []

class Solution
{
public:
    int getResult(std::vector<int> &nums, int k)
    {

        const auto beginIterator = nums.begin();
        const auto endIterator = nums.end();
        const auto numsSize = nums.size();

        std::sort(beginIterator, endIterator);

        auto maxRemovableItem = std::upper_bound(beginIterator, endIterator, k);

        // If K is largest than all values in array than, we can remove all of them
        if (maxRemovableItem == endIterator)
            return numsSize;

        // If first greater value is first item, that we cant remove anything
        if (maxRemovableItem == beginIterator && *maxRemovableItem > k)
            return 0;

        // If value that we found is not equal to k, then previous value will be greater value than lower than k
        if (*maxRemovableItem != k)
            maxRemovableItem = std::prev(maxRemovableItem);

        auto removeCount = std::distance(beginIterator, maxRemovableItem);

        for (auto forwarder = maxRemovableItem; forwarder != endIterator && k + removeCount >= *forwarder; ++forwarder)
            ++removeCount;

        return removeCount;
    }
};

#endif
