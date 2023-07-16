#pragma once

struct PairHash {
public:
    template<typename T1, typename T2>
    int32_t operator()(const std::pair<T1, T2> &pair) const {
        return std::hash<T1>{}(pair.first) ^ std::hash<T2>{}(pair.second);
    }
};

template<typename T>
struct PairComparator {
    bool operator()(const T &left, const T &right) const {
        return (left.first == right.first && left.second == right.second);
    }
};
