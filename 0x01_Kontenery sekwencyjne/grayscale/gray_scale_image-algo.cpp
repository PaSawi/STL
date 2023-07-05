#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <ranges>
#include <utility> //std::pair
#include <vector>

constexpr size_t width = 32;
constexpr size_t height = 32;

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, height>, width>& bitmap)
{
    std::vector<std::pair<uint8_t, uint8_t>> vec_c;
    vec_c.reserve(width * height);
    int counter = 0;
    auto last_color = bitmap[0][0];
    for (const auto& row : bitmap) {
        std::transform(row.begin(), row.end(), std::back_inserter(vec_c),
            [&counter, row, &last_color](uint8_t value) mutable {
                if (value == last_color) {
                    counter++;
                    return std::pair<uint8_t, uint8_t>(value, counter);
                }
                else {
                    counter = 1; 
                    last_color = value;
                    return std::pair<uint8_t, uint8_t>(value, counter); 
                }
            });
    }
    return vec_c;

    /*   for (const auto& row : bitmap) {
           std::transform(row.begin(), row.end(), std::back_inserter(vec_c),
                          [](uint8_t value) {
                              return std::pair<uint8_t, uint8_t>(value , 0);
                          });
       }

       return vec_c;
       */
}

/*bitmap = { { { 0, 0, 0, 1, 1, 2, 3, 0, 0, 0 },
                     { 0, 0, 4, 4, 4, 1, 1, 1, 1, 1 },
                     { 2, 2, 2, 2, 2, 1, 2, 2, 2, 2 } } };*/
// vec_c = {0, 4}, {1, 2}, {2, 1}, {3, 1}, {0, 27}, {4, 3}, {1, 5}, {0, 22}, {2, 5}, {1, 1}, {2, 4}, {0, 182},

int main()
{
    std::array<std::array<uint8_t, height>, width>
        bitmap = { { { 0, 0, 0, 1, 1, 2, 3, 0, 0, 0 },
            { 0, 0, 4, 4, 4, 1, 1, 1, 1, 1 },
            { 2, 2, 2, 2, 2, 1, 2, 2, 2, 2 } } };
    std::vector<std::pair<uint8_t, uint8_t>> vec_c = compressGrayscale(bitmap);
    std::ranges::for_each(vec_c, [](const std::pair<uint8_t, uint8_t>& p) {
        std::cout << "{" << static_cast<int>(p.first) << ", " << static_cast<int>(p.second) << "}, ";
    });
    std::cout << std::endl;
    return 0;
}

/*
std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, height>, width>& bitmap)
{
    std::vector<std::pair<uint8_t, uint8_t>> vec_c;
    uint8_t last_color = bitmap[0][0];
    uint8_t count = 1;
    for (int row = 0; row < width; row++) {
        for (int col = 0; col < height; col++) {
            if (bitmap[row][col] == last_color) {
                count++;
            } else {
                vec_c.push_back(std::make_pair(last_color, count));
                last_color = bitmap[row][col];
                count = 1;
            }
        }
    }
    vec_c.push_back(std::make_pair(last_color, count));
    return vec_c;
}*/