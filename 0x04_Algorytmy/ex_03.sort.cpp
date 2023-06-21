// sort algorithms

#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>

struct Point { int x, y; };

// Create a function to output the contents of container d
template <typename Container>
void print(Container c) {
    for (const auto & el : c){
        std::cout<< el.x <<", " << el.y << '\t';
    }
    std::cout<< '\n';
}

int main()
{
    std::deque<Point> d = {{1, 3}, {0, 0}, {1, 2}, {2, 4}, {4, 1}, {0, 2}, {2, 2}};
    print(d);
    return 0;
}


// Write 2 comparators:
// pointXCompare, which compares only the x values from the Point structure
// pointYCompare, which compares only the y values from the Point structure
// Check if d is sorted against pointXCompare and pointYCompare
// Use stable_sort to sort d against x values
// Use sort to sort d against y values