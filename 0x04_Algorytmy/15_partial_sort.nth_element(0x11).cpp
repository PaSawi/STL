// std::partial_sort, std::nth_element

#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <vector>

int main()
{
    std::vector<int> v { 5, 6, 4, 3, 2, 6, 7, 9, 3 };
    std::nth_element(v.begin(), v.begin() + v.size() / 2, v.end());
    std::cout << "The median is " << v[v.size() / 2] << '\n'; // 5
    // possible content of v = {3, 2, 3, 4, 5, 6, 7, 9, 6}

    std::array<int, 10> s { 5, 7, 4, 2, 8, 6, 1, 9, 0, 3 };
    std::partial_sort(s.begin(), s.begin() + 3, s.end());

    // possible content of s = {0, 1, 2, 7, 8, 6, 5, 9, 4, 3}

    return 0;
}