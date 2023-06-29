#include <iostream>
#include <map>
#include <string>


int main(){

    std::map<int, std::string> m{ { 1, "one" }, { 2, "two" }, { 3, "thr" }, { 4, "four" }, { 5, "five" } };
    m.emplace(3,"three");
    m.erase(5);

    for(auto &el : m){
        std::cout << el.first << ": " << m.count(el.first) << "\n";
    }
    for(int i = 1; i <=5; i++){
        std::cout << i << ": " << m.count(i) << "\n";
    }

    auto it4 = m.find(4);
    std::cout << it4->first <<": " <<it4->second << "\n";
}

// count - returns the number of elements matching specific key



