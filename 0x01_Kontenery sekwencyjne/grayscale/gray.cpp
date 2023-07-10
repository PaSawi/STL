#include <array>
#include <iostream>
#include <utility>
#include <vector>

constexpr size_t width = 3;
constexpr size_t height = 10;


std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, height>, width>& bitmap)
{
    std::vector<std::pair<uint8_t, uint8_t>> compressed;
    uint8_t last_color = bitmap[0][0];
    uint8_t count = 1;
    int temp = 0;

    for (int row = 0; row < width; row++) {
        for (int col = 0; col < height; col++) {
            if (bitmap[row][col] == last_color && temp == 0) {
                count++;
            } else {
                compressed.push_back(std::make_pair(last_color, count));
                last_color = bitmap[row][col];
                count = 1;
                temp = 0;
            }
        }
        temp = 1;
    }
    compressed.push_back(std::make_pair(last_color, count));
    return compressed;
}

int main()
{
    std::array<std::array<uint8_t, height>, width>
        bitmap = { { { 0, 0, 0, 1, 1, 2, 3, 0, 0, 0 },
            { 0, 0, 4, 4, 4, 1, 1, 1, 1, 1 },
            { 2, 2, 2, 2, 2, 1, 2, 2, 2, 2 } } };
    std::vector<std::pair<uint8_t, uint8_t>> compressed = compressGrayscale(bitmap);
    for (auto& p : compressed) {
        std::cout << "{" << static_cast<int>(p.first) << ", " << static_cast<int>(p.second) << "}, ";
    }
    std::cout << std::endl;
    return 0;
}