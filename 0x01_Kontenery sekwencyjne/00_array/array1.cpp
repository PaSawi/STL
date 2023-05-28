#include <iostream>
#include <array>

void print(const std::array<int, 10>& arr){
    for (const auto& el : arr){
        std::cout << el << ' ';
    }
    std::cout<<'\n';
}
int main(){

    std::array<int, 4> numbers {3, 1, 4, 1};
    std::array<int, 0> no_numbers;
 
    std::cout << std::boolalpha;
    std::cout << "numbers.empty(): " << numbers.empty() << '\n';
    std::cout << "no_numbers.empty(): " << no_numbers.empty() << '\n';

    std::array<int, 10> other{};
    std::array<int, 10> a2{};
    other.fill(0);
    std::cout << "other.empty(): " << other.empty() << '\n';
    print(other);
    other.swap(a2);
    std::cout << "a2.empty(): " << a2.empty() << '\n';
    print(other);
    
    //std::array<int,10> arr {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout<<sizeof(a2) << '\n';
    //print(arr);
}