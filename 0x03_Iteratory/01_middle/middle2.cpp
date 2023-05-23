#include<iostream>

template <typename Iter>
auto printMiddle2(Iter first, Iter last) {
   auto size = std::distance(first, last);
   std::advance(first, size / 2);
   return *first;
}