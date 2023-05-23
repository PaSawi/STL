#include <iostream>
#include <vector>

void display(std::vector<int> ve) {
    for (auto& el : ve) {
        std::cout << el << " ";
    }
    std::cout << "\n";
}
int main() {
    std::vector<int> v{1, 2, 4, 5, 6};
    auto it = v.begin();
    v.erase(it);
    v.emplace_back(5);
    v.emplace(v.begin(), 12);
    std::cout << "size: " << v.size() << " max_size: " << v.max_size();
    std::cout << "\n";
    display(v);
    v.clear();
    std::cout << "size: " << v.size() << " max_size: " << v.max_size();
    std::cout << "\n";
}