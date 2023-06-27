#include <iostream>
#include <vector>
#include<iterator>
int main()
{
    std::vector<int> v = { 8, 2, 5, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9 };
// Write out all elements, using std::copy and std::ostream_iterator
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout<<'\n';
    return 0;
}