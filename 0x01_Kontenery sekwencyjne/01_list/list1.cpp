
#include <array>
#include <iostream>
//#include <numeric>
#include <list>


template<typename T>
void print(const std::list<T>& list){
    for (const auto& el : list){
        std::cout << el << " ";
    }
    std::cout<<'\n';
}

template<typename T, std::size_t N>
void printA(const std::array<T, N>& array){
    for (const auto& el : array){
        std::cout << el << " ";
    }
    std::cout<<'\n';
}

int main()
{
    std::list<int> list {0,1,2,3,4,5};
    print(list);
    auto it = list.begin();
    std::advance(it,2);
    list.erase(it);
    print(list);
    list.push_front(10);
    list.push_back(10);
    print(list);
    std::advance(it,3);
    list.insert(it,20);
    print(list);
    it = list.begin();

    std::array<int, 10> arr;
    printA(arr);
    it = list.begin();
    for(size_t i = 0; i < list.size(); ++i){    
        arr[i] = *it++;
    }
    std::cout<<"sizeof()= " << sizeof(list) <<'\n';
    printA(arr);
}