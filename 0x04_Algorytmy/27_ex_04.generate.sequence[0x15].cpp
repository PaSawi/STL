
#include <algorithm>
#include <execution>
#include <iostream>
#include <iterator>
#include <list>
#include <numeric>
#include <vector>
#include <functional>

int main()
{
    // Create vector v1 with numbers from 1 to 1000Utwórz wektor v1 z liczbami od 1 do 1000
    std::vector<int> v1(10, 0);
    std::iota(v1.begin(), v1.end(), 1);
    std::copy(v1.begin(), v1.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';

    // Calculate the sum of these numbers
    auto sum = std::reduce(std::execution::par, v1.begin(), v1.end());
    std::cout << "sum = " << sum << '\n';
    std::cout << '\n';

    // Create a v2 vector of 1000 elements repeating in the following sequence: -1, 0, 1, 0, -1, 0, 1, 0, ...
    std::vector<int> v2(10);
    std::vector<int> v_seq { -1, 0, 1, 0 };
    std::generate(std::execution::par,v2.begin(), v2.end(), [v_seq, i = 0]() mutable { return v_seq[i++ % v_seq.size()]; });
    std::copy(v2.begin(), v2.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';

    // Calculate the scalar product of vectors v1 and v2
    int r = std::transform_reduce(std::execution::par,v1.begin(), v1.end(), v2.begin(), 0 );
    std::cout<< " scalar = " << r <<'\n'; 

    // Calculate the sum of those numbers from v1 that are at the positive positions of the ones from vector v2
    auto sum_only_with1 = std::transform_reduce(std::execution::par, v1.begin(), v1.end(), v2.begin(), 0,
                                                std::plus(),
                                                [](int p, int q){
                                                    return  q == 1 ? p : 0;
                                                } );
    std::cout<< " sum_only_with1 = " << sum_only_with1 <<'\n'; 
}