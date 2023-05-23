#include <iostream>
#include <forward_list>

template<typename T>
void print(const std::forward_list<T>& f_list){
    for (const auto& el : f_list){
        std::cout << el << " ";
    }
    std::cout<<'\n';
}

int main(){
    std::forward_list<int> f_list {0,1,2,3,4,5,6};
    print(f_list);
    auto it = f_list.before_begin();
    std::advance(it, 2);
    f_list.erase_after(it);
    print(f_list);
    it = f_list.before_begin();
    std::advance(it, 3);
    f_list.insert_after(it,20);
    std::cout<<"sizeof()= " << sizeof(f_list) <<'\n';
    print(f_list);
}