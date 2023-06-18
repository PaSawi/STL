#include <array>
#include <deque>
#include <iostream>
#include <forward_list>
#include <list>
#include <string>
#include <vector>

#include "middle.cpp"
#include "middle2.cpp"
#include "printCollection.cpp"
/*
template <typename Iter>
auto printMiddle(Iter first, Iter last) {
   auto size = std::distance(first, last);
   std::advance(first, size / 2);
   return *first;
}

auto printMiddle(std::vector<int>::iterator first, std::vector<int>::iterator last) {
   auto size = last - first;
   return *(first + size / 2);
}

auto printMiddle(std::forward_list<std::string>::iterator first, std::forward_list<std::string>::iterator last) {
   auto middle = first;
   bool even = false;
   while(first != last) {
      first++;
      if (even){
         middle++;
      }
      even = !even;
   }
   return *middle;
}
*/

int main()
{
    std::array<int, 9> a{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::deque<double> d{1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8};
    std::forward_list<std::string> fl{"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    std::list<std::string> l{"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};

    std:: cout << printMiddle(a) <<" ";
    std:: cout << printMiddle(d) <<" ";
    std:: cout << printMiddle(fl) <<" ";
    std:: cout << printMiddle(l) <<" ";
    std:: cout << printMiddle(v) <<" ";
    std::cout<<'\n';

    std::cout<< "printMiddle2\n";  
    std::cout<< printMiddle2(a.begin(),  a.end()) << " ";
    std::cout<< printMiddle2(d.begin(),  d.end()) << " ";
    std::cout<< printMiddle2(fl.begin(), fl.end())<< " ";
    std::cout<< printMiddle2(l.begin(),  l.end()) << " ";
    std::cout << printMiddle2(v.begin(), v.end()) << " ";
    
    /*
    std::cout<<'\n';
    printCollection(a);
    printCollection(d);
    printCollection(fl);
    printCollection(l);
    printCollection(v);*/
    std::cout << "TEH END\n";
}