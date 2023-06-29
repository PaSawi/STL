#include <algorithm>
#include <array>
#include <execution>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <numeric>
#include <ranges>
#include <vector>

// 0. Jaką złożoność ma std::sort()?
//    complexity is O(N·log(N)) comparisons

int main()
{
    std::vector<int> vec1 { 1, 2, 3, 4, 5, 6, 7, 8 };
    std::vector<int> vec2 { 10, 20, 30, 40, 50, 60, 70, 80 };
    std::vector<std::array<int, 2>> result;

    // 1. połączyć 2 kontenery naprzemiennie?
    result.reserve(vec1.size() + vec2.size());
    std::ranges::transform(vec1, vec2, std::back_inserter(result), [](auto a, auto b) {
        return std::array<int, 2> { a, b };
    });
    for (const auto& arr : result) {
        std::cout << arr[0] << " " << arr[1] << " "; // << std::endl;
    }
    std::cout << '\n';

    /* auto size = std::max(vec1.size(), vec2.size());
     for( auto i = 0; i < size; ++i ) {
         if (i < vec1.size())
             result.push_back(vec1[i]);
         if (i < vec2.size())
             result.push_back(vec2[i]);
     std::ranges::copy(result, std::ostream_iterator<int>(std::cout, " "));
     }*/

    // 2. zsumować wszystkie elementy w std::vector?
    auto sum = std::reduce(std::execution::par, vec1.begin(), vec1.end(), 0);
    std::cout << "sum vec1: " << sum << '\n';

    // 3. pomnożyć 2 kontenery ze sobą?
    auto multiply = std::transform_reduce(vec1.begin(), vec1.end(), vec2.begin(), 0);
    std::cout << "multiply vec1 * vec2: " << multiply << '\n';

    // 4. usunąć liczby parzyste?
    std::vector<int> v { 4, 4, 2, 7, 12, 6, 6, 1, 8, 9 };
    v.erase(std::remove_if(v.begin(), v.end(), [](auto num) { return (num & 1) == 0; }), v.end());
    std::cout << "only even from v: ";
    std::ranges::copy(v, std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';

    // 5. wypełnić strukturę wartościami od 0 do n?
    std::list<int> list(10);
    std::ranges::generate(list, [i { 0 }]() mutable { return i++; });
    std::cout << "list: ";
    std::ranges::copy(list, std::ostream_iterator<int>(std::cout, " "));

    std::cout << '\n';

    // 6. zawsze na 1. miejscu (0 index) znajdował się największy element?
    std::vector<int> vec { 4, 4, 2, 7, 12, 6, 6, 1, 8, 9 };
    auto max_part_sort = std::ranges::partial_sort(vec, vec.begin() + 1, [](auto a, auto b) { return a > b; });
    std::cout << "partial_sorted: ";
    std::ranges::copy(vec, std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';

    // 7. wyszukać czy dana liczba znajduje się w posortowanym kontenerze?
    std::vector<int> vec3 { 1, 2, 3, 4, 5, 6, 7, 8 };
    auto num = 10;
    std::cout << std::boolalpha << "binary find number: " << std::ranges::binary_search(vec3, num);
    std::cout << '\n';

    // 8. podzielić kontener na 2 zakresy, zawierające mniejsze i większe wartości niż 10?
    std::ostream_iterator<int> cout { std::cout, " " };
    std::vector<int> v4 { 4, 15, 4, 2, 10, 7, 12, 6, 6, 1, 60, 8, 9 };
    auto less_than_10 = [](auto num) { return num < 10; };
    std::ranges::partition(v4, less_than_10);
    std::cout << "partition relative to 10: ";
    std::ranges::copy(v4, cout);
    std::cout << '\n';

    // partition_copy
    std::vector v5 = { 4, 15, 4, 2, 10, 7, 12, 6, 6, 1, 60, 8, 91, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::vector<int> true_vector;
    std::vector<int> false_vector;
    std::ranges::partition_copy(v5,
        std::back_inserter(true_vector),
        std::back_inserter(false_vector),
        less_than_10);
    std::cout << "part less than 10: ";
    std::ranges::copy(true_vector, cout);
    std::cout << '\n';
    std::cout << "part greater than 10: ";
    std::ranges::copy(false_vector, cout);
    std::cout << '\n';

    // 9. zmienić kolejność 2 elementów w kontenerze?
    std::vector<int> vec6 { 1, 2, 3, 4, 5, 6, 7, 8 };
    std::swap(vec6[1], vec6[2]);
    std::cout << "swap two elements in vector: ";
    std::ranges::copy(vec6, cout);
    std::cout << '\n';

    return 0;
}
