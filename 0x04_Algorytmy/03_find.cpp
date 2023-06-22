// std::find, distance()
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main()
{
    std::vector<int> v { 5, 7, 4, 9, 8, 3, 8, 2, 9 };
    // find '8' in subrange
    auto i = find(begin(v) + 2, begin(v) + 7, 8);
    // i != end-of-range?
    std::cout << *i << '\n';
    if (i != begin(v) + 7) {
        std::cout << *i << '\n';
    }
    // find '9' in entire vector:
    auto j = find(begin(v), end(v), 9);
    if (j != end(v)) { // true ⇒ found
        auto const value = *j; // int value = 9
        auto const index = distance(begin(v), j); // index = 0
        std::cout << "value = " << value << ", index = " << index << '\n';
    }
    // find '7' in entire vector:
    auto k = find(begin(v), end(v), 7);
    if (k != end(v)) {
        std::cout << *k << '\n';
    } // false ⇒ NOT found
    return 0;
}