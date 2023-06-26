// std::is_sorted, std::stable_sort, std::sort

#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
#include <vector>

struct Point {
    int x, y;
};

// Create a function to output the contents of container d
template <typename Container>
void print(Container collection)
{
    for (const auto& el : collection) {
        std::cout << el.x << ", " << el.y << '\t';
    }
    std::cout << '\n';
}

int main()
{
    std::deque<Point> d = { { 1, 3 }, { 0, 0 }, { 1, 2 }, { 2, 4 }, { 4, 1 }, { 0, 2 }, { 2, 2 } };
    print(d);

// Write 2 comparators:
// pointXCompare, which compares only the x values from the Point structure
// pointYCompare, which compares only the y values from the Point structure
    auto pointXCompare = [](const auto& lhs, const auto& rhs) {
        return lhs.x < rhs.x;
    };
    auto pointYCompare = [](const auto& lhs, const auto& rhs) {
        return lhs.y < rhs.y;
    };
// Check if d is sorted against pointXCompare and pointYCompare
    std::cout << std::boolalpha << std::is_sorted(d.begin(), d.end(), pointYCompare) << '\n';

// Use stable_sort to sort d against x values
    std::stable_sort(d.begin(), d.end(), pointXCompare);
    print(d);
// Use sort to sort d against y values
    std::sort(d.begin(), d.end(), pointYCompare);
    print(d);

    return 0;
}