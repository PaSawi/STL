#include <iostream>
#include <vector>

template <typename T>

void printV(const std::vector<T>& v)
{
    for (const auto& el : v) {
        std::cout << el << " ";
    }
    std::cout << '\n';
}

void removeVowels(std::vector<std::string>& vec)
{
    for (auto& word : vec) {
        auto it = word.begin();
        for (auto& ch : word) {
            if (*it == 'a' || *it == 'e' || *it == 'y') {
                word.erase(it);
            } else {
                it++;
            }
        }
    }
}

void removeVowels2(std::vector<std::string>& vec)
{
    for (auto& word : vec) {
        std::size_t poz = word.find_first_of("aoeiyuAOEIYU");
        while (poz != std::string::npos) {
            word.erase(poz, 1);
            if (poz != std::string::npos)
                poz = word.find_first_of("aeioyuAOEIY", poz);
        }
    }
}

int main()
{

    std::vector<std::string> vec { "abcde", "aabbbccabc", "qwerty" };
    printV(vec);
    removeVowels2(vec);
    printV(vec);
}