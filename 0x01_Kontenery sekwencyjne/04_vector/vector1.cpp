#include <iostream>
#include <list>
#include <vector>

void print(std::vector<int> v){
    for(const auto& el : v){
        std::cout << el << " ";
    }
    std::cout <<'\n';
}



int main()
{
    struct Point2d {
        int x;
        int y;
    };

    std::vector<Point2d> vec3{{1,1}, {2,0}, {-3,10}};
    vec3.push_back({5,2});
    //vec3.emplace_back(5,2);

    std::vector <int> empty;
    std::vector vec1 { 1, 2, 3, 4, 5, 6 };
    std::vector vec2 (5,1);
    std::list<int> list{10, 20,30, 40};
    auto it = vec2.begin();
    vec2.insert(it, 3, 21);
    vec2.insert(vec2.begin() + 2, list.begin(), list.end());

    vec1.erase(vec1.begin());
    vec1.push_back(5);
    vec1.emplace(vec1.begin(), 12);
    std::cout<<"size()= " << vec1.size() << " max_size()= " << vec1.max_size() << '\n';
    print(vec1);
    vec1.clear();
    std::cout<<"size()= " << vec1.size() << " max_size()= " << vec1.max_size() << '\n';
    print(vec1);
    
    std::cout<<"size()= " << empty.size() << " capacity()= " << empty.capacity() << '\n';
    print(empty);

    empty.resize(1000,5);
    std::cout<<"size()= " << empty.size() << " capacity()= " << empty.capacity() << '\n';
    print(empty);
    empty.reserve(20);
    std::cout<<"size()= " << empty.size() << " capacity()= " << empty.capacity() << '\n';
    empty.shrink_to_fit();
    std::cout<<"size()= " << empty.size() << " capacity()= " << empty.capacity() << '\n';
    std::cout<<"sizeof()= " << sizeof(empty) <<'\n';
    
    
    
    
    print(vec2);

}