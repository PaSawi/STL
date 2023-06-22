// is_partition, partition, partition_point, stable_partition

#include "printCollection.cpp"
#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <vector>


using namespace std;

int main()
{
    auto is_even = [](auto i) { return i % 2 == 0; }; // predicate

    std::array<int, 9> a1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::cout << std::is_partitioned(a1.begin(), a1.end(), is_even); // false
    std::vector a2 = { 2, 4, 6, 8, 9 };
    std::cout << std::is_partitioned(a2.begin(), a2.end(), is_even); // true
    std::array<int, 9> a4 = { 9, 5, 3 };
    std::cout << std::is_partitioned(a4.begin(), a4.end(), is_even); // false!

    // pp
    vector<int> v = { 8, 2, 6, 4, 5, 3, 7, 1, 9 };
    auto it = std::partition(v.begin(), v.end(), is_even);
    std::cout << std::is_partitioned(v.begin(), v.end(), is_even); // true
    auto pp = std::partition_point(v.begin(), v.end(), is_even);
    std::cout << '\n'
              << *pp << '\n'; // 5

    // stable_partition vs partition
    std::vector v1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::stable_partition(v1.begin(), v1.end(), is_even); // relative order of data
    // = {2, 4, 6, 8, 1, 3, 5, 7, 9}
    std::vector v2 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::partition(v2.begin(), v2.end(), is_even); // random data
    // v = {8, 2, 6, 4, 5, 3, 7, 1, 9}

    // partition_copy
    std::vector v3 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::vector<int> true_vector;
    std::vector<int> false_vector;
    std::partition_copy(v3.begin(),
        v3.end(),
        std::back_inserter(true_vector),
        std::back_inserter(false_vector),
        is_even);
    printCollection(true_vector); // true_vector = {2, 4, 6, 8}
    printCollection(false_vector); // false_vector = {1, 3, 5, 7, 9}

    // Wypisanie zawartości true_vector
    std::copy(true_vector.begin(), true_vector.end(),
        std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    // Wypisanie zawartości false_vector
    std::copy(false_vector.begin(), false_vector.end(),
        std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}