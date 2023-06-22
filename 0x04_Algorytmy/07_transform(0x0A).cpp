//std::transform
#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
#include "printCollection.cpp"

int main(){
    std::vector<int> vec {1,2,3,4,5,6,7,8};
    std::list<int> list {10,20,30,40,50,60,70,80};
    std::transform(begin(vec),
                   end(vec),
                   begin(list),
                   end(list),
                   [](auto first, auto second){
                        return first + second;
                   });
     // vec = {11, 22, 33, 44, 55, 66, 77, 88}
}