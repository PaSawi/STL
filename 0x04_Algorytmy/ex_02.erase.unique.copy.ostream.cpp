#include "printCollection.cpp"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>


int main()
{
    std::vector<int> v = { 8, 2, 5, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9 };

    // Remove all duplicates from v
    printCollection(v);
    v.erase(std::unique(begin(v), end(v)), end(v));

    // Write out all elements, using std::copy and std::ostream_iterator
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout<<'\n';

    // Mix all the elements randomly
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(v.begin(),v.end(), g);
    
    // Print them out again
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout<<'\n';

}