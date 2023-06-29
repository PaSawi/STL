
#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <ranges>
#include <vector>

int main()
{
    constexpr std::array v { 4, 4, 2, 7, 12,  6, 6, 1, 8, 9 };
    //constexpr std::array v {1, 2, 3, 4, 4, 3, 7, 8, 9, 10};
    std::cout << "v: ";
    // Write out all elements, using std::copy and std::ostream_iterator
    std::copy(v.cbegin(), v.cend(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';

    // determine how many integers match a target value.
    for (const int target : {3,4,5,8}){
        const int num_items = std::ranges::count(v, target);
        std::cout << "number: " <<target << ", count: " <<num_items << '\n';
    }

    // use a lambda expression to count elements divisible by 4.
    int count_div4 = std::ranges::count_if(v, [](auto a){
        return a % 4 == 0;  
    });
    std::cout << "number of element div by 4: " << count_div4 << ", count:  \n";

    // A simplified version of `distance` with O(N) complexity:
    auto distance = [](auto first, auto last){
        return std::count_if(first, last, [](auto) {return true;});
    };
    //static_assert(distance(v.begin(), v.end()) == 10);
    static_assert(std::ranges::distance(v) == 10);
    
    return 0;
}