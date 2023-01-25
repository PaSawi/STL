#include <algorithm>
#include <array>
#include <iostream>
#include <list>

using namespace std;

void dispList(list<int> l) {
  for (auto& el : l) {
    cout << el << " ";
  }
  cout << "\n";
}

int main() {
  list<int> l{0, 1, 2, 3, 4, 5};
  array<int, 10> arr{};
  dispList(l);
  l.remove(2);
  dispList(l);
  l.emplace_front(20);
  l.emplace_back(20);
  dispList(l);

  auto it = next(l.begin(), 4);
  l.emplace(it, 20);
  dispList(l);

  copy(l.begin(), l.end(), arr.begin());
  cout << "array: ";
  for (auto& i : arr) {
    cout << i << " ";
  }
  cout << "\n";
}