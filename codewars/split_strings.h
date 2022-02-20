#pragma once
#include <vector>
#include <string>
#include <sstream>


class Solution
{
public:
    std::vector<std::string> splitStrings(const std::string &s)
    {
        const auto subrangeLength = 2;
        std::vector<std::string> ranges;
        {
            const auto sizeEven = s.size() % 2 == 0;
            const auto sourceEndIterator = sizeEven ? s.end() : std::prev(s.end());

            for (auto rangeStart = s.begin(), rangeEnd = std::next(rangeStart, subrangeLength); rangeStart < sourceEndIterator;) {
                ranges.emplace_back(rangeStart, rangeEnd);
                rangeStart = std::next(rangeStart, subrangeLength);
                rangeEnd = std::next(rangeStart, subrangeLength);
            }

            if (!sizeEven && !s.empty()) {
                std::string lastItem;
                std::stringstream ss(lastItem);
                ss << s.back() << "_";
                ranges.emplace_back(std::move(ss.str()));
            }
        }
        return ranges;
    }
};