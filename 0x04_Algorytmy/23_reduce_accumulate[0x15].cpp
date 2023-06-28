// std::accumulate, std::reduce(C++17),  std::accumulate = std::reduce, std::reduce is prefer
// std::execution::par (C++17)
#include <execution> //C++17
#include <iostream>
#include <iterator>
#include <list>
#include <numeric>
#include <vector>

int main()
{
    std::vector<int> v { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int sum = std::accumulate(v.begin(), v.end(), 0);
    int product = std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());
    std::cout << "std::accumulate\tsum = " << sum << "\tproduct = " << product << '\n';
    // sum = 55, product = 3628800

    sum = std::reduce(std::execution::par, v.begin(), v.end(), 0); // std::execution::par jest to typ wyliczeniowy (enum class) reprezentujący politykę wykonania
                                                                   // algorytmów równoległych. Polityka par oznacza równoległe wykonanie algorytmu, jeśli to możliwe.
    product = std::reduce(v.begin(), v.end(), 1, std::multiplies<>());  //type type in std::multiplies is note necessary
    // sum = 55, product = 3628800
    std::cout << "std::reduce\tsum = " << sum << "\tproduct = " << product << '\n';

    std::vector<double> w {2.0, 1.5, 3.0, 1.5};
    auto const product2 = reduce(begin(w), end(w), 1.0, std::multiplies<>{});  
    // double product2 = 1.0 * 2.0 * 1.5 * 3.0 * 1.5 = 13.5
    std::cout << '\n';
}