#include <deque>
#include <forward_list>
#include <iostream>
#include <algorithm>

template <typename T>
void printD(const std::deque<T>& deq)
{
    for (auto& el : deq) {
        std::cout << el << " ";
    }
    std::cout << '\n';
}

template <typename T>
void printFL(const std::forward_list<T>& fl)
{
    for (auto& el : fl) {
        std::cout << el << " ";
    }
    std::cout << '\n';
}

template <typename Container>
void printCollection(const Container& collection){
    for(const auto& element : collection) {
        std::cout << element << ' ';
    }
    std::cout << '\n';
}

bool compare(std::string s1, std::string s2){

return (s1.size() < s2.size());
}

std::deque<std::string> lengthSort(std::forward_list<std::string> fl)
{
    fl.sort();
    fl.sort(compare);
    std::deque<std::string> deq;
    for(auto it = fl.begin(); it != fl.end(); ++it){
        deq.push_back(*it);
    }
    return deq;
}

int main()
{
    std::forward_list<std::string> fl { "Z", "Three","b" , "tata", "One", "A", "a", "Four", "Two" };
    std::deque<std::string> deq = lengthSort(fl);
    printFL(fl);
    printD(deq);

    printCollection(fl);
    printCollection(deq);
    
}