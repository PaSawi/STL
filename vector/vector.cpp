
#include <iostream>
#include <string>
#include <vector>

template <typename T>
void printVector(const std::vector<T>& collection) {
    for (const auto& element : collection) {
        std::cout << element << " ";
    }
    std::cout << '\n';
}

std::vector<int> solution(std::vector<std::string>& S) {
    std::vector<int> sV;
    if (S.size() < 2) {
        return sV;
    }
    sV.reserve(3);

    for (unsigned int lP = 0; lP < S.size() - 1; lP++) {
       // std::cout << "lP: " << lP << " ";
        for (unsigned int rP = (lP + 1); rP < S.size(); rP++) {
            //std::cout << "rP: " << rP << " ";
            for (unsigned int i = 0; i < S[0].size(); i++) {
                if (S[lP][i] == S[rP][i]) {
                    sV.emplace_back(lP);
                    sV.emplace_back(rP);
                    sV.emplace_back(i);
                    return sV;
                }
            }
        }
    }

    return sV;
}



int main() {
    // tests
    std::vector<std::string> v1{"abc", "bca", "dbe"};             // [0,2,1]
    std::vector<std::string> v2{"zzzz", "ferz", "zdsr", "fgtd"};  // [0,1,3]
    std::vector<std::string> v3{"pati", "goty", "xxxx", "oioo"};  // [0,1,2]
    std::vector<std::string> v4{"gr", "sd", "rg"};                // []
    std::vector<std::string> v5{"abc", "prs", "krt"};             // [1,2,1]
    std::vector<std::string> v6{"abc", "bca", "dpa"};             // [1,2,2]
    std::vector<std::string> v7{};                                // []

    printVector(solution(v1));
    printVector(solution(v2));
    printVector(solution(v3));
    printVector(solution(v4));
    printVector(solution(v5));
    printVector(solution(v6));
    printVector(solution(v7));
}