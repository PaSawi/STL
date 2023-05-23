#include <iostream>
#include <vector>

void print(std::vector<int> ve) {
  for (const auto &el : ve) {
    std::cout << el << " ";
  }
  std::cout << "\n";
}

int main() {
  std::vector<int> v;
  std::cout << "size: " << v.size() << " capacity: " << v.capacity() << "\n";
  v.resize(10, 5);
  std::cout << "size: " << v.size() << " capacity: " << v.capacity() << "\n";
  v.reserve(20);
  std::cout << "size: " << v.size() << " capacity: " << v.capacity() << "\n";
  v.shrink_to_fit();
  std::cout << "size: " << v.size() << " capacity: " << v.capacity() << "\n";
  print(v);
}