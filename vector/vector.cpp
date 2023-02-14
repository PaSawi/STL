
#include <iostream>
#include <string>
#include <vector>

template <typename T> void printVector(const std::vector<T> &collection) {
  for (const auto &element : collection) {
    std::cout << element << " ";
  }
  std::cout << '\n';
}

std::vector<int> solution(std::vector<std::string> &S) {
  std::vector<int> sV{0, 0, 0};
  sV.reserve(3);
  printVector(S);
  int i{};

  std::string temp = *(S.begin());
  sV[0] = 0;
  for (auto it = S.begin(); it <= S.end() - 1; it++, i++) {
    for (unsigned int j = 0; j < temp.length(); j++) {
      if (temp[j] == (*it)[j]) {
        sV[1] = i;
        sV[2] = j;
        break;
      }
    }
  }

  return sV;
}

int main() {
  std::vector<std::string> v1{"abc", "bca", "dbe"};            // [0,2,1]
  std::vector<std::string> v2{"zzzz", "ferz", "zdsr", "fgtd"}; // [0,1,3]
  std::vector<std::string> v3{"gr", "sd"};                     // []

  printVector(solution(v1));
  printVector(solution(v2));
  printVector(solution(v3));
}