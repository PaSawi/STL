#include <array>
#include <iostream>

void display(std::array<int, 10> ar) {
    for (auto& el : ar) {
        std::cout << el << " ";
    }
    std::cout << "\n";
}

int main() {
    std::array<int, 10> a1{};
    a1.fill(5);
    a1[3] = 3;
    display(a1);
    std::array<int, 10> a2{};
    display(a2);
    a1.swap(a2);
    display(a1);
    display(a2);
}

