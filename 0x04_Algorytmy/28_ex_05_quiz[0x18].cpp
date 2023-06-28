#include<algorithm>
#include<vector>
#include<list>
#include<iostream>
#include<iterator>
#include<numeric>
#include<execution>

int main()
{
    std::vector<int> vec1 {1,2,3,4,5,6,7,8};
    std::vector<int> vec2 {10,20,30,40,50,60,70,80};
// 1. połączyć 2 kontenery naprzemiennie?
    for(auto i = vec1.begin(); i != vec1.end() ; i++ ){
        auto j = vec2.begin();
        vec1.insert(j);
    }
    
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