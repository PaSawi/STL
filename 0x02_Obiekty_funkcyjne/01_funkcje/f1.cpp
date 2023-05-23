#include <iostream>


int compute(int a, int b, int (*operation)(int, int)) {  // auto is conceptual, it may not work
    return operation(a, b);
}

int sum(int a, int b) {
    return a + b;
}

int multi(int a, int b) {
    return a * b;
}

int main(){

auto s = compute(2, 3, sum);    // s = 5
auto m = compute(2, 3, multi);  // m = 6
std::cout << " s = " << s <<'\n';
std::cout << " m = " << m <<'\n';
}

