#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <ranges>
#include <utility>  //std::pair
#include <vector>

constexpr size_t width = 32;
constexpr size_t height = 32;
/*
std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, height>, width>& bitmap)
{
    std::vector<std::pair<uint8_t, uint8_t>> compressed;
    uint8_t last_color = bitmap[0][0];
    uint8_t count = 1;
    for (int row = 0; row < width; row++) {
        for (int col = 0; col < height; col++) {
            if (bitmap[row][col] == last_color) {
                count++;
            } else {
                compressed.push_back(std::make_pair(last_color, count));
                last_color = bitmap[row][col];
                count = 1;
            }
        }
    }
    compressed.push_back(std::make_pair(last_color, count));
    return compressed;
}*/

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, height>, width>& bitmap)
{
    std::vector<std::pair<uint8_t, uint8_t>> compressed;
    compressed.reserve(width * height);

    /*auto transformFunction = [&](uint8_t value) {
        return std::pair<uint8_t, uint8_t>(value, value);
    };

    std::transform(bitmap.begin(), bitmap.end(), std::back_inserter(compressed),
        [](const auto& row){
            return std::transform(row.begin(), row.end(), row.begin(), transformFunction);
        });*/

    return compressed;
}

int main()
{
    std::array<std::array<uint8_t, height>, width>
        bitmap = { { { 0, 0, 0, 1, 1, 2, 3, 0, 0, 0 },
                     { 0, 0, 4, 4, 4, 1, 1, 1, 1, 1 },
                     { 2, 2, 2, 2, 2, 1, 2, 2, 2, 2 } } };
    std::vector<std::pair<uint8_t, uint8_t>> compressed = compressGrayscale(bitmap);
    std::ranges::for_each(compressed, [](const std::pair<uint8_t, uint8_t>& p) {
        std::cout << "{" << static_cast<int>(p.first) << ", " << static_cast<int>(p.second) << "}, ";
    });
    std::cout << std::endl;
    return 0;
}