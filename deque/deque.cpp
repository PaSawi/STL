#include <cstdlib>
#include <ctime>
#include <deque>
#include <iostream>
using namespace std;

void dispDeque(deque<int>& deq) {
    for (auto& el : deq) {
        cout << el << " ";
    }
    cout << "\n";
}

int main() {
    deque<int> d;
    srand(static_cast<int>(time(nullptr)));
    for (int i = 0; i < 5; i++) {
        int randV = (rand() % 50);
        d.emplace_back(randV);
    }
    d.emplace_back(3);
    dispDeque(d);
    d.erase(d.begin() + 1);
    dispDeque(d);
    d.erase(d.begin() + 3);
    dispDeque(d);
    d.push_front(30);
    d.push_back(30);
    dispDeque(d);
    d.emplace(d.begin() + 3, 20);
    dispDeque(d);
}
