#include <iostream>

template <typename Container>
auto printMiddle(const Container& collection)
{
    auto first = collection.begin();
    auto last = collection.end();
    auto size = std::distance(first, last); 
    std::advance(first, size / 2);
    return *first;
}