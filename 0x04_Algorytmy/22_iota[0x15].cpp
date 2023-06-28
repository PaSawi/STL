
// std::iota , similar to generate
#include <iostream>
#include <iterator>
#include <list>
#include <numeric>
#include <vector>

int main()
{
    std::list<char> l(10);
    std::iota(l.begin(), l.end(), 'C');
    std::copy(l.begin(), l.end(), std::ostream_iterator<char>(std::cout, " "));
    std::cout << '\n';
    // l = {'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L'}

    std::vector<int> v;
    v.resize(9, 0);
    // fill subrange (as shown in image)
    iota(begin(v) + 2, begin(v) + 7, 1);
    for (int x : v) {
        std::cout << x << ' ';
    } // 0 0 1 2 3 4 5 0 0
    std::cout << '\n';

    // fill entire vector
    iota(begin(v), end(v), 3);
    for (int x : v) {
        std::cout << x << ' ';
    } // 3 4 5 6 7 8 9 10 11
    std::cout << '\n';
}