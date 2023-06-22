
#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <vector>

int main()
{
    std::vector<int> v = { 8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9 };
    
    //2. Find all elements greater than 6 and list them
    auto it = std::find_if(begin(v), end(v), [](auto el) { return el > 6; });
    while (it != v.end()) {
        std::cout << *it << " ";
        it = std::find_if(std::next(it), v.end(), [](auto el) { return el > 6; });
    }
    std::cout << '\n';

    std::copy_if   (v.begin(), 
                    v.end(), 
                    std::ostream_iterator<int>(std::cout, " "),// write on screen 
                    [](auto el){ return el > 6; });
    std::cout << '\n';

    //3. Find all elements equal to 2, 4, 6 or 8 and list them
    std::copy_if  (v.begin(), 
                        v.end(),
                        std::ostream_iterator<int>(std::cout, " "), 
                        [] ( auto el){
                            return el == 2 || el == 4 || el == 6 || el == 8;
                        });
    std::cout << '\n';
    
    //4. Search the vector v for ranges {6, 6} and {7, 7}
    std::array<int, 2> a = {6,6};
    it = std::search(v.begin(), v.end(), a.begin(), a.end());
    if ( it != v.end()) {
        std::cout << *it <<" ";
        it++;
        std::cout << *it <<" ";
        it++;
        std::cout << *it <<'\n';
    }

    it = std::search_n(v.begin(), v.end(),2 , 6);
    if ( it != v.end()) {
        std::cout << *it <<" ";
        it++;
        std::cout << *it <<" ";
        it++;
        std::cout << *it <<'\n';
    }

    auto found = std::ranges::search(v, std::vector{6,6});
    if(!found.empty()){
        for (const auto el :found) {
            std::cout << el;
        }
    }

    // 5. Use std::adjacent_find on the vector v
    it = std::adjacent_find(v.begin(), v.end()); //search for repetition
    if ( it != v.end()) {
        std::cout << *it <<" ";
        it++;
        std::cout << *it <<" ";
        it++;
        std::cout << *it <<'\n';
    }

    return 0;
}