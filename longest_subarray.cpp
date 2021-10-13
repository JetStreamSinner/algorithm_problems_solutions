#ifndef LONGEST_SUBARRAY
#define LONGEST_SUBARRAY

#include <vector>
#include <string>
#include <algorithm>

class LongestSubarray
{
public:
    static int solution(const std::vector<int> &values)
    {
        auto currentSequence = 0;
        auto previousSequence = 0;
        auto maxSequenceSize = 0;

         for (const auto item : values){
            if (item == 1) {
                ++currentSequence;
                ++previousSequence;
            } else {
                previousSequence = currentSequence;
                currentSequence = 0;
            }
            maxSequenceSize = std::max(maxSequenceSize, std::max(currentSequence, previousSequence));
        }

        return std::min<int>(maxSequenceSize, values.size() - 1);
    }
};

#endif