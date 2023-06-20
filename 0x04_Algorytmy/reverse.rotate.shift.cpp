#include <algorithm>
#include <iostream>
#include <vector>
#include "printCollection.cpp"

int main()
{
     int a[] = {4, 5, 6, 7, 8};
     std::reverse(std::begin(a), std::end(a));
     printCollection(a);

     std::vector<int> v{2,4,2,0,5,10,7,3,7,1};
     std::rotate(v.begin(), v.begin() + 3, v.end());
     printCollection(v);

     std::vector<std::string>  c{"a", "b", "c", "d", "e", "f", "g"};
     std::shift_left(begin(c), end(c), 3);
     printCollection(c);
     std::shift_right(begin(c), end(c), 2);
     printCollection(c);
}