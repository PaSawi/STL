#include <algorithm>
#include <array>
#include <execution>
#include <iostream>
#include <iterator>
#include <list>
#include <numeric>
#include <vector>
#include <ranges>

int main() {
    std::vector<int> vec1{1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<int> vec2{10, 20, 30, 40, 50, 60, 70, 80};
    std::vector<std::array<int,2>> result;
    // 1. połączyć 2 kontenery naprzemiennie?
    result.reserve(vec1.size() + vec2.size());
    std::ranges::transform(vec1, vec2, std::back_inserter(result), [](auto a, auto b){
        return std::array<int,2> {a,b} ;
    } );
   
    std::cout <<'\n';
    for(const auto& arr : result) {
        std::cout << arr[0] << " " << arr[1] << " "; // << std::endl;
    }
    std::cout <<'\n';
    
   /* auto size = std::max(vec1.size(), vec2.size());
    for( auto i = 0; i < size; ++i ) {
        if (i < vec1.size())
            result.push_back(vec1[i]);
        if (i < vec2.size())
            result.push_back(vec2[i]);
    std::ranges::copy(result, std::ostream_iterator<int>(std::cout, " "));
    }*/

        return 0;
}

// Jaką złożoność ma std::sort()?
// complexity is O(N·log(N)) comparisons

// Jakiego algorytm użyjesz, aby:
// 2. zsumować wszystkie elementy w std::vector?
// 3. pomnożyć 2 kontenery ze sobą?
// 4. usunąć liczby parzyste?
// 5. wypełnić strukturę wartościami od 0 do n?
// 6. zawsze na 1. miejscu (0 index) znajdował się największy element?
// 7. wyszukać czy dana liczba znajduje się w posortowanym kontenerze?
// 8. podzielić kontener na 2 zakresy, zawierające mniejsze i większe wartości niż 10?
// 9. zmienić kolejność 2 elementów w kontenerze?