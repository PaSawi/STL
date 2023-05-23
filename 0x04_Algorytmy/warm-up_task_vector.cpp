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