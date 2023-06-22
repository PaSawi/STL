#include <algorithm>
#include <iostream>
#include <vector>

int main(){
    std::vector<int> v = {10,22,33,44,55,88,33,55};
    std::vector<int> z = {88,33,55};
    auto it = std::ranges::find_if(v, [](auto el) { return el > 10; });
    //Very important. We should check if the iterator is in range or equal to end(), which means out of range
    auto check_out_of_range = [v] (auto it) { 
        if (it != v.end()) return *it;
        else 
            return 0;
    };
    std::cout << check_out_of_range(it) << '\n';
    
    //std::find_first_of() searches the second container and provides the value from the iterator position of the first element that is a common part of both containers
    auto it2 = std::ranges::find_first_of(v,z);  
    std::cout << check_out_of_range(it2) << '\n';

    //std::search() provides the value from the iterator position of the first element from the sequence from second container if that sequence is a common part of both containers
    auto it3 = std::search(begin(v),end(v),begin(z),end(z));  
    std::cout << check_out_of_range(it3) << '\n';
    
    //std::adjacent()
    auto it4 = std::search(begin(v),end(v),begin(z),end(z));  
    std::cout << check_out_of_range(it4) << '\n';

    return 0;
}