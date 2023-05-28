
// 1. Utwórz std::vector<int> v = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9}; (ten sam co ostatnio)
// 2. Znajdź wszystkie elementy większe od 6 i wypisz je
// 3. Znajdź wszystkie elementy równe 2, 4, 6 lub 8 i wypisz je
// 4. Przeszukaj wektor v w poszukiwaniu zakresów {6, 6} i {7, 7}
// 5. Użyj std::adjacent_find na wektorze v

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main()
{
    std::vector<int> v = { 8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9 };

    auto it = std::find_if(begin(v), end(v), [v](auto el) { return el > 6; });
    while (it != v.end()) {
        std::cout << *it << " ";
        it = std::find_if(std::next(it), v.end(), [](auto el) { return el > 6; });
    }
    std::cout << '\n';
}