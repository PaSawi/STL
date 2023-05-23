#include <iostream>
#include <vector>
#include <algorithm>

struct Functor {
    void operator() () {
        std::cout << "I'm a functor!\n";
    }
};

struct Functor2 {
    void operator() (int el) {
        std::cout << el << ' ';
        if(el==3){ std::cout <<" I'am tree ";} 
    }
};

struct Functor3 {
    int index = 0;  // odpowiednik [ ]  w lambdzie

    void operator()(int el) {
       std::cout << index << ": " << el << " | " ;
       index++; 
    }
};

struct Functor_if_divisible_by_6{
    bool operator()(int number){
        return !(number%6);
    }   
};


int main(){
    Functor funct{};
    funct(); //named object
    Functor3 funct3{};
    
    std::vector<int> vec {1, 2, 3, 4, 5};
    std::for_each(begin(vec), end(vec), Functor2{});
    std::cout << '\n';
    std::for_each(vec.begin(), end(vec), Functor3{});
    std::cout<<'\n';
    std::for_each(vec.begin(), end(vec), funct3);
    funct3(6);
    funct3(7);
    funct3(7);
    funct3(7);
    funct3(7);
    funct3(7);
    funct3(7);
    funct3(7);




    
    Functor{}(); //temporary object
    std::cout << Functor_if_divisible_by_6{}(6000000);
    return 0;
}