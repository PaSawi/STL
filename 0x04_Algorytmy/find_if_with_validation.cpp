#include <algorithm>
#include <iostream>
#include <vector>

int main(){
    std::vector<int> v = {1,2,3,4,5};
    auto it = std::ranges::find_if(v, [](auto el) { return el > 4; });
    //Very important. We should check if the iterator is in range or equal to end(), which means out of range
    if (it != v.end()) {
        std::cout << *it;
    }
    else
        std::cout << "You are out of range";
    return 0;
}