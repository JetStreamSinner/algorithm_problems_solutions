#ifndef BALANCE_PARENTHESES_H
#define BALANCE_PARENTHESES_H

#include <algorithm>
#include <numeric>
#include <iostream>
#include <vector>

//  Вы играете в игру, где ваш персонаж прыгает по заборчикам. Значения в массиве означают, сколько заборчиков персонаж обязан перешагнуть, двигаясь вперед, начиная с этого индекса.
//  Например, в массиве 2, 1, 0 с нулевого индекса нужно прыгнуть на второй индекс,
//  с первого - прыгнуть на второй, со второго - остаться на месте. Вы можете менять элементы в массиве местами.
//  А за пределами всего массива пропасть, из которой нельзя вылезти.
//
//  Чтобы выиграть, персонажу нужно с нулевого индекса дойти до последнего. Выведите true, если победить в игре возможно, в противном случае - false.
//  Ввод:
//  fences - массив значений длин прыжков. Персонаж начинает с нулевого индекса, 1 < length(fences) <= 20, -10 <= fences[i] <= 15
//
//  Вывод:
//  Boolean - возможно ли победить. Победить нельзя, если даже при перестановках элементов в массиве дойти до последнего индекса в массиве персонажу будет невозможно

class Solution
{
public:
    bool getResult(std::vector<int> &fences)
    {
        const auto beginIterator = fences.begin();
        const auto endIterator = fences.end();

        std::sort(beginIterator, endIterator, std::greater<>());

        auto fencesPermutations = permute(fences);

        const auto target = fences.size();
        return std::any_of(fencesPermutations.begin(), fencesPermutations.end(), [&](const auto &permutation) {
            return checkPermutation(permutation, target);
        });
    }
private:

    bool checkPermutation(const std::vector<int> &permutation, int target) const
    {
        auto accumulator = 0;
        for (auto value : permutation) {
            accumulator += value;
            if (accumulator == target)
                return true;
        }
        return false;
    }

    template<typename T>
    void permutationForIndex(int startIndex, T &&temp, std::vector<std::vector<int>> &permutationAccumulator, const std::vector<int> &source, std::vector<bool> &used)
    {
        bool permutationDone = temp.size() == source.size();
        if (permutationDone) {
            permutationAccumulator.push_back(temp);
            return;
        }

        if (startIndex >= source.size())
            return;

        const auto numsCount = source.size();
        for (auto index = 0; index < numsCount; ++index) {
            if (used.at(index))
                continue;
            temp.push_back(source.at(index));
            used.at(index) = true;

            permutationForIndex(index, temp, permutationAccumulator, source, used);

            used.at(index) = false;
            temp.pop_back();
        }
    }

    std::vector<std::vector<int>> permute(std::vector<int>& nums)
    {
        std::vector<std::vector<int>> result;
        const auto numsCount = nums.size();
        for (auto index = 0; index < numsCount; ++index) {
            std::vector<bool> used(numsCount);
            used.at(index) = true;
            permutationForIndex(index, std::vector<int>{nums.at(index)}, result, nums, used);
        }
        return result;
    }
};

#endif
