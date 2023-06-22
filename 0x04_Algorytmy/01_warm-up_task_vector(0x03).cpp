//lambda, std::for_each
#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    [&v]() { 
        for(const auto& n : v){
            std::cout << n << " ";
        }
        std::cout << '\n';
    }();

    auto f = [](int a) {
        std::cout << a << ' ';
    };
    f(42);

    std::for_each(v.begin(),v.end(), f);
    //lub
    std::for_each(v.begin(),v.end(), [](auto a) {
        std::cout << a << " " ;
    } );
}

// *_if - takes a predicate instead of a value
//   std::find(v.begin(), v.end(), 5);
//   std::find_if(v.begin(), v.end(), [](auto x){ return x > 5; });

// *_copy - saves the result in another container
//   std::reverse(v.begin(), v.end());
//   std::reverse_copy(v.begin(), v.end(), r.begin());

// *_n - takes n elements / performs n operations instead of specifying an iterator last
//   std::fill(v.begin(), v.end(), -1);
//   std::fill_n(v.begin(), 5, -1);

// ranges:: - works on whole containers (C++20)
//   std::sort(v.begin(), v.end());
//   std::ranges::sort(v);
