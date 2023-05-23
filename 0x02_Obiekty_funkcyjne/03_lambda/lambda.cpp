#include <algorithm>
#include <iostream>
#include <vector>
int main()
{
    // lambda 1
    std::vector<int> vec { 1, 2, 3, 4, 5 };
    for_each(begin(vec), end(vec), [index = 0](int el) mutable {
        std::cout << index << ": " << el << " | ";
        index++; });
    std::cout << '\n';

    // lambda 2
    []() { std::cout << "Hello \n"; }();

    // lambda 3
    std::cout << "---------------------------------- \n";
    std::cout << "Erase_Remove Idiom \n";
    std::cout << "Leave numbers divisible by 2\n";
    std::vector<int> vec3 { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    vec3.erase(std::remove_if(vec3.begin(), vec3.end(), [](int num) { return num % 2; }),
        vec3.end());

    // lambda 4 - printing Erase-Remove Idiom
    auto print = [](int num) { std::cout << num << ' '; };
    std::for_each(vec3.begin(), vec3.end(), print);
    std::cout << "\n----------------------------------- \n";

    // lambda 5
    int number = 10;
    auto add10 = [number](int num) { return num + number; };
    std::cout << add10(20) << '\n';

    // labmda gneryczna 6
    auto multiplyByX = [&number](auto num) { return num * number; };
    std::cout << multiplyByX(20) << '\n';
    std::cout << multiplyByX(3.14) << '\n';

    // Zadanie1
    // Utwórz lambdę, która przyjmie 2 argumenty typu int oraz zwróci ich iloczyn
    auto multiplyXbyY = [](auto x, auto y) { return x * y; };
    std::cout << "Zadanie 1" << '\n';
    std::cout << multiplyXbyY(3, 4) << '\n';
    std::cout << multiplyXbyY(1.1, 5) << '\n';

    // Zadanie2
    // Utwórz lambdę, która do podanego ciągu znaków doda cudzysłów
    auto quotationMarks = [](std::string wyraz) { return '"' + wyraz + '"'; };
    std::cout << "Zadanie 2" << '\n';
    std::cout << quotationMarks("tralalala") << '\n';
    std::cout << quotationMarks("tuutuututuutu") << '\n';

    // Zadanie3
    // Utwórz lambdę, która wypisze ciąg znaków *. Przy każdym zawołaniu funkcji powinniśmy dostać ciąg dłuższy o jedną *

    auto AddStar = [index = 1]() mutable {
        for(int i = 0; i < index ; ++i) {
            std::cout<< "*";}
        std::cout<<'\n';
        index++; };
    std::cout << "Zadanie 3\n";
    AddStar();
    AddStar();
    AddStar();
    AddStar();

    // Zadanie4
    // Utwórz std::vector<int> i wypełnij go dowolnymi wartościami
    std::cout << "Zadanie 4 i 5 \n";
    std::vector<int> v5 { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    // Zadanie5
    // Utwórz lambdę, która przechwyci ten wektor przez capture list, oraz wyświetli jego zawartość
    auto capture = [v5]() { 
        for(auto el : v5) {
            std::cout <<' ' << el << " ";
        }
        ; };
    capture();
    //Zadanie6
    //Utwórz lambdę, która w swoim argumencie przyjmie int i go wyświetli
    std::cout<<"\nZadanie 6 \n";
    auto print2 = [](auto num) { std::cout << " " << num << " "; };
    print2(4);
    //Zadanie7
    //Wykorzystaj lambdę z pkt. 6 w algorytmie std::for_each() do wyświetlenia całego kontenera
    std::cout<<"\nZadanie 7 \n";
    std::for_each(v5.begin(),v5.end(),print2);

    return 0;
}