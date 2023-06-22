//std::count_if, std::any_of, std::all_of
//std::ranges::any_of, all_of
//std::boolalpha
#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v = { 8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9 };
    // Count how many elements are greater than or equal to 5
    int count_5 = std::count_if(begin(v), end(v), [v](auto el) { return el >= 5; });
    std::cout << "Numbers greater equal to 5: " << count_5 << '\n';

    // Check if there is an element less than 1
    if (std::any_of(v.cbegin(), v.cend(), [](int i) { return i < 1; }))
        std::cout << "The claim that there is an element in the container that is smaller than 1 is TRUE\n";
    else
        std::cout << "The claim that there is an element in the container that is smaller than 1 is FALSE\n";
        
    // Check that all elements are greater than 1
    if (std::all_of(v.cbegin(), v.cend(), [](int i) { return i > 1; }))
        std::cout << "The claim that there all elements in the container are greater than 1 is TRUE\n";
    else
        std::cout << "The claim that there all elements in the container are greater than 1 is FALSE\n";
    //new c++20 with ranges
    std::cout << std::boolalpha << std::ranges::any_of(v, [](int i) { return i < 1; });
    std::cout << std::boolalpha << std::ranges::all_of(v, [](int i) { return i > 1; });
}

//std::boolalpha << std:: - displays TRUE and FALSE except 1 i 0

// Checking conditions - std::all_of, std::any_of, std::none_of
// Counting elements - std::count, std::count_if
// Searching for elements - std::find_if, std::find_first_of, std::search, std::adjacent_find
// Comparing - std::mismatch