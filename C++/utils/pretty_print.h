#pragma once
#include <ostream>

#include <type_traits>
#include <map>
#include <unordered_map>
#include <vector>

template<typename ValueType>
void vectorPrinterImpl(std::ostream& os, const std::vector<ValueType>& container)
{
    os << "{";

    auto forwardIterator = container.begin();
    const auto endIterator = container.end();

    while (forwardIterator != endIterator) {
        const auto lineEnder = std::next(forwardIterator) == endIterator ? "" : ", ";
        os << *forwardIterator << lineEnder;
        ++forwardIterator;
    }
    os << "}";
}

template<typename Map>
void mapPrinterImpl(std::ostream& os, Map &&map)
{
    os << "{" << std::endl;

    auto forwardIterator = map.begin();
    const auto endIterator = map.end();

    while (forwardIterator != endIterator) {
        const auto lineEnder = std::next(forwardIterator) == endIterator ? "" : ", ";
        os << "    " << forwardIterator->first << " : " << forwardIterator->second << lineEnder << std::endl;
        forwardIterator = std::next(forwardIterator);
    }

    os << "}";
}


template<typename ValueType>
std::ostream& operator<<(std::ostream& os, const std::vector<ValueType>& container)
{
    vectorPrinterImpl(os, container);
    return os;
}

template<typename Key, typename MappedValue>
std::ostream& operator<<(std::ostream& os, const std::map<Key, MappedValue>& container)
{
    mapPrinterImpl(os, container);
    return os;
}

template<typename Key, typename MappedValue>
std::ostream& operator<<(std::ostream& os, const std::unordered_map<Key, MappedValue>& container)
{
    mapPrinterImpl(os, container);
    return os;
}