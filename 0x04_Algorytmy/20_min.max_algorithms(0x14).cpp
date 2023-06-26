// std::min, std::max, std::minmax (work on values)
// std::min_element, std::max_element, std::minmax_element (work on iterators)
// std::clamp(c++17)
#include <algorithm>
#include <iostream>
#include <vector>


int main()
{
//std::min
    int const a = 2;
    int const b = 9;
    int x_min = std::min(a, b); // int x = 2
    std::cout <<"x = std::min(a, b) = " << x_min << '\n';

    struct P {
        int q;
        char c;
    };
    P p_min = std::min(P { 1, 'y' }, P { 2, 'x' },
        [](P p1, P p2) { return p1.q < p2.q; });    // P p_min {1,'y'};
    std::cout << "P p_min = { " <<  p_min.q << ", " << p_min.c << " }\n";

//std::max
    //int const a = 2;
    //int const b = 9;
    int x_max = std::max({3,4,b,3,a,8});  // int x = 9
    std::cout <<"std::max = " << x_max << '\n';

//std::minmax
    auto p = std::minmax({3,0,b,3,a,8});  // std::pair<int,int> p {0,9}
    auto min = p.first;  // int min = 0
    auto max = p.second; // int max = 9
    auto [lo,hi] = std::minmax({3,0,b,3,a,8});  // int lo = 0, hi = 9  C++17
    std::cout << "minmax_lo = " << lo << " minmax_hi = " << hi <<'\n';

// std::clamp
std::cout << "std::clamp from v: ";
    for (auto v : { 10, 200, -1, 23, 101, 55 }) { // std::initializer_list
        std::cout << std::clamp(v, 0, 100) << " ";
    }
    // output: 10, 100, 0, 23, 100, 55
    // if value is less than 0 then will return , if value is greater than 100 then will return 100,
    // if value is in the range (0,100) then will return the value.

return 0;
}