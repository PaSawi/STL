#include <algorithm>
#include <iterator>
#include <iostream>
#include <random>
#include <vector>
#include "printCollection.cpp"

int main()
{
     std::vector<int> vec(10);
     std::generate(begin(vec), end(vec), [i{0}]() mutable { return i++; });
     std::cout<<"Generate: ";
     printCollection(vec);  
     
     std::mt19937 rng;
     std::cout<<"Generate_n: ";
     std::generate_n(   std::ostream_iterator<std::mt19937::result_type>(std::cout, " "),  //display on screen
                        5,
                        std::ref(rng));
}