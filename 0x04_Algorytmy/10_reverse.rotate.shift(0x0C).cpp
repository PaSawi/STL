// std::reverse, std::rotate
// std::shift_left, std::shift_right
#include "printCollection.cpp"
#include <algorithm>
#include <iostream>
#include <vector>


int main()
{
    int a[] = { 4, 5, 6, 7, 8 };
    std::reverse(std::begin(a), std::end(a));
    printCollection(a);  // a = {8, 7, 6, 5, 4};

    std::vector<int> v { 2, 4, 2, 0, 5, 10, 7, 3, 7, 1 };
    std::rotate(v.begin(), v.begin() + 3, v.end());
    printCollection(v);  // v = {0, 5, 10, 7, 3, 7, 1, 2, 4, 2}

    std::vector<std::string> c { "a", "b", "c", "d", "e", "f", "g" };
    std::shift_left(begin(c), end(c), 3);
    printCollection(c);  // c = {"d", "e", "f", "g", "", "", ""}
    std::shift_right(begin(c), end(c), 2);
    printCollection(c);  // c = {"", "", "d", "e", "f", "g", ""}
}