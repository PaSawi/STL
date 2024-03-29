//std::generate, std::generate_n
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
      // Possible output: 3499211612 581869302 3890346734 3586334585 545404204                   
}

// std::generate generates values "from nothing"
// std::transform transforms values from another container
// Both take a functor that tells you how to generate/transform elements
// To cast in new elements, use std::back_inserter(v) as the target iterator
// You can use std::ostream_iterator<T>(std::cout, " ") as the target iterator to display the result on the screen!