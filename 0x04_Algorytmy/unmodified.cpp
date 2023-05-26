#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v = { 8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9 };
    int count_5 = std::count_if(begin(v), end(v), [v](auto el) { return el >= 5; });
    std::cout << "Numbers greater equal to 5: " << count_5 << '\n';
    if (std::any_of(v.cbegin(), v.cend(), [](int i) { return i < 1; }))
        std::cout << "The claim that there is an element in the container that is smaller than 1 is TRUE\n";
    else
        std::cout << "The claim that there is an element in the container that is smaller than 1 is FALSE\n";

    if (std::all_of(v.cbegin(), v.cend(), [](int i) { return i > 1; }))
        std::cout << "The claim that there all elements in the container are greater than 1 is TRUE\n";
    else
        std::cout << "The claim that there all elements in the container are greater than 1 is FALSE\n";
}