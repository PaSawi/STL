//vector<std::pair<int, std::string>> v
//std::transform, std::generate_n 

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "printCollection.cpp"


int main()
{
    std::vector<std::pair<int, std::string>> v {
        { 0, "Zero" }, { 1, "One" }, { 2, "Two" }, { 3, "Three" }, { 4, "Four" }, { 5, "Five" }
    };

    // Create a vector of ints v2 and fill it with all the ints (the first elements of the pair) from the vector v
    std::vector<int> v2(v.size(), 0xFF); // fill the vector with the numbers 255
    std::transform(begin(v), end(v), begin(v2), [](auto p) { return p.first; }); // std::back_inserter(v2) adds an element to the end of the vector)
    printCollection(v2);

    // Create a string vector v3 and fill it with the concatenation of string + colon + int from all pairs in the vector v
    std::vector<std::string> v3(v.size());
    std::transform(begin(v), end(v), begin(v3), [](auto p) { return p.second + ":" + std::to_string(p.first); });  
    printCollection(v3);

    // Create a v4 char vector and fill it with every second letter of the alphabet
    constexpr auto size = 13;
    std::vector<char> v4(size);
    std::generate_n(begin(v4), size, [c = 'a' - 2]() mutable { c += 2; return c; });
    printCollection(v4);
}