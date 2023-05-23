/******************************************************************************
Usuwanie (prawie)
std::remove() z nagłówka <algorithm>
Ponieważ najszybciej usuwane są elementy z końca wektora, biblioteka STL umożliwia nam przygotowanie std::vector<T> 
do usunięcia elementów poprzez przeniesienie tych, które są nieprzeznaczone do usunięcia, na początek kontenera. 
W wyniku tego część wartości do usunięcia jest nadpisywana wartościami z końca wektora, które nie powinny zostać usunięte. 
Na końcu wektora pozostają "śmieci", które należy wymazać (ang. erase) z pamięci.

std::vector<int> vec {1, 4, 2, 4, 3, 4, 5};
std::remove(vec.begin(), vec.end(), 4);
// e.g. vec {1, 2, 3, 5, 3, 4, 5}



Usuwanie (tak serio)
std::vector<T>::erase()
iterator erase( const_iterator first, const_iterator last );
Dzięki tej metodzie usuwamy niepotrzebne dane z kontenera:

std::vector<int> vec {1, 4, 2, 4, 3, 4, 5};
auto it = std::remove(vec.begin(), vec.end(), 4);
vec.erase(it, vec.end()); // vec {1, 2, 3, 5}
albo zapisane za pomocą , czyli:


*******************************************************************************/
#include <algorithm>
#include <iostream>
//#include <vector>

template<typename Container>
void pirntCollection(const Container& collection){
    for(const auto& el : collection ){
        std::cout << el << " ";
    }
    std::cout <<'\n';
}    


int main()
{
    std::vector<int> vec {1, 4, 2, 4, 3, 4, 5};
    auto it = std::remove(vec.begin(), vec.end(), 4);
    vec.erase(it, vec.end()); // vec {1, 2, 3, 5}
    pirntCollection(vec);
    
    //Erase-Remove Idiom
    vec.erase(std::remove(vec.begin(), vec.end(), 3), vec.end());  
    //std::remove() zwróci iterator, który wskazuje na początek danych przeznaczonych do usunięcia.
    pirntCollection(vec);
    return 0;
}
