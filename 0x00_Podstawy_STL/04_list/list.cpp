#include <iostream>
#include <list>
#include <numeric> 
#include <vector>

template <typename T>
void printList(const std::list<T>& list)
{
    for (const auto& el : list) {
        std::cout << el << " ";
    }
    std::cout << "\n";
}

int main()
{
/*    std::list<int> l;

   // l.resize(1'000'000);
    for (int i = 0; i <= 1000000; i++) {
        l.emplace_back(i);
    }
   // std::iota(l.begin(), l.end(), 1);

    auto it = l.begin();
    std::advance(it, 500'000);
    std::cout << *it << std::endl;

*/
    std::vector<int> v;
    v.reserve(1'000'000);
    std::iota(v.begin(), v.end(), 1);
    std::cout << v[500'000] << std::endl;
}