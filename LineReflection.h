#ifndef LINEREFLECTION_H
#define LINEREFLECTION_H

#include <vector>
#include <set>

class LineReflection
{
public:
    bool solution(const std::vector<std::pair<int, int>> &points)
    {
        using Point = std::pair<int, int>;
        int minX = std::numeric_limits<int>::min();
        int maxX = std::numeric_limits<int>::max();

        std::set<Point> uniquePoints;
        for (const auto &point : points) {
            minX = std::min(point.first, minX);
            maxX = std::max(point.first, maxX);
            uniquePoints.insert(point);
        }

        int middleLine = (minX + maxX) / 2;

        for (const auto &point : uniquePoints) {
            const auto reflectedX = point.first + (middleLine - point.first) * 2;
            const Point reflectedPoint = std::make_pair(reflectedX, point.second);

            if (uniquePoints.find(reflectedPoint) != uniquePoints.cend())
                return false;
        }
        return true;
    }

};

#endif
