
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
  if (S.size() < 2) {
    return sV;
  }

  sV.reserve(3);
  printVector(S);
  int lP{0};
  int rP{1};

  for (auto itS = (S.begin() + 1); itS < S.end(); itS++, lP++) {
    std::string temp = *(S.begin() + lP);
    std::cout << " temp: " << temp << " itS: " << *itS << " ";

    for (auto it = S.begin() + rP; it < S.end(); it++, rP++) {
      for (auto itL = temp.begin(), itR = (*it).begin(); itL < temp.end();
           itL++, itR++) {
        if (*itL == *itR) {
          sV[0] = lP;
          sV[1] = rP;
          sV[2] = static_cast<int>(std::distance(temp.begin(), itL));
          break;
        }
      }
    }
  }
  return sV;
}

int main() {
  // tests
  std::vector<std::string> v1{"abc", "bca", "dbe"};            // [0,2,1]
  std::vector<std::string> v2{"zzzz", "ferz", "zdsr", "fgtd"}; // [0,1,3]
  std::vector<std::string> v3{"pati", "goty", "xxxx", "oioo"}; // [0,1,2]
  std::vector<std::string> v4{"gr", "sd", "rg"};               // []
  std::vector<std::string> v5{"abc", "prs", "krt"};            // [1,2,1]
  std::vector<std::string> v6{"abc", "bca", "dpa"};            // [1,2,2]

  printVector(solution(v1));
  printVector(solution(v2));
  printVector(solution(v3));
  printVector(solution(v4));
  printVector(solution(v5));
  printVector(solution(v6));
}