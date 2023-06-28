
#include <algorithm>
#include <execution>
#include <iostream>
#include <iterator>
#include <list>
#include <numeric>
#include <vector>

int main()
{
//Create vector v1 with numbers from 1 to 1000Utwórz wektor v1 z liczbami od 1 do 1000
    std::vector<int> v(100,0);
    std::iota(v.begin(), v.end(), 1 );
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
//Calculate the sum of these numbers
    auto sum = std::reduce(std::execution::par, v.begin(), v.end());
    std::cout <<"sum = " << sum <<'\n';
    std::cout << '\n';
//Create a v2 vector of 1000 elements repeating in the following sequence: -1, 0, 1, 0, -1, 0, 1, 0, ...
    std::vector<int> v2(100);
    int seq[] = { -1, 0, 1, 0};
    std::copy(std::begin(seq), std::end(seq), v2.begin());
    std::copy(v2.begin(), v2.end(), std::ostream_iterator<int>(std::cout, " "));
    std::fill(v2.begin(), v2.back(),[](auto i){
        return 0; });

    // Calculate the scalar product of vectors v1 and v2
    // Calculate the sum of those numbers from v1 that are at the positive positions of the ones from vector v2
}