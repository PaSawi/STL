// s std::equal_range, std::lower_bound, std::upper_bound,
// std::binary_search
#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
// std::binary_search
    std::vector<int> v { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
    // search in subrange (as in image):
    std::cout << binary_search(begin(v) + 2, begin(v) + 7, 4) << '\n'; // true
    // search in entire vector:
    std::cout << binary_search(begin(v), end(v), 8) << '\n'; // true
    std::cout << binary_search(begin(v), end(v), 9) << '\n'; // false

// std::lower_bound, std::lower_bound zwraca iterator na pierwszy element NIE MNIEJSZY NIŻ podana wartość
    //  find in subrange (as shown in image):
    auto i = lower_bound(begin(v) + 3, begin(v) + 7, 5);
    if (i != end(v)) { // true => found
        std::cout << *i << '\n'; // 5
    }
    // find in entire vector
    auto j = lower_bound(begin(v), end(v), 2);
    if (j != end(v)) { // true => found
        std::cout << *j << '\n'; // 2
    }

//std::upper_bound,  std::upper_bound zwraca iterator na pierwszy element WIĘKSZY NIŻ podana wartość
    // find in subrange (as shown in image):
    auto p = upper_bound(begin(v)+3, begin(v)+7, 5);
    if (p != end(v)) {  // true => found
      std::cout << *p << '\n';  // 6
    }
    // find in entire vector
    auto q = upper_bound(begin(v), end(v), 2);
    if (q != end(v)) {  // true => found
      std::cout << *q << '\n';  // 3
    }

//std::equal_range,std::equal_range zwraca parę [lower_bound, upper_bound], 
//std::distance pomiędzy lower i upper to liczba znalezionych, równych sobie elementów
    std::vector<int> vec {1,1,2,3,4,5,5,5,6,6,7,7,8};
    // find in subrange (as shown in image):
    auto r5 = equal_range(begin(vec)+3, begin(vec)+11, 5);
    // erase range of '5'
    v.erase(r5.first, r5.second);
    for (int x : vec) { std::cout << x << ' '; }  // 1 1 2 3 4 6 6 7 7 8
    std::cout << '\n';

    // find in entire vector
    auto r6 = equal_range(begin(vec), end(vec), 6);
    // erase range of '6'
    v.erase(r6.first, r6.second);
    for (int x : vec) { std::cout << x << ' '; }  // 1 1 2 3 4 7 7 8
    std::cout << '\n';

    std::vector<int> data = { 1, 2, 2, 4, 5, 5, 5, 6 };
    auto [l_1, u_1] = std::equal_range(data.begin(), data.end(), 5);
    // data = { 1, 2, 2, 4, 5, 5, 5, 6 };
    //                      l        u
    auto [l_2, u_2] = std::equal_range(data.begin(), data.end(), 3);
    // data = { 1, 2, 2, 4  , 5, 5, 5, 6 };
    //                   l=u

    return 0;
}
