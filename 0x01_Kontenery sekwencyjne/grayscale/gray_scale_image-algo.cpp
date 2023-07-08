#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
//#include <ranges>
#include <utility> //std::pair
#include <vector>

constexpr size_t width = 3;
constexpr size_t height = 10;

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, height>, width>& bitmap)
{
    std::vector<std::pair<uint8_t, uint8_t>> vec_c;
    vec_c.reserve(width * height);
    auto last_color = bitmap[0][0];
    int counter = 0;

    for (const auto& row : bitmap)
    {      
        std::transform(row.begin(), row.end(), std::back_inserter(vec_c),
           [&counter, &last_color, &bitmap](uint8_t value) mutable {          
               if (value == last_color) {
                   counter++;
               }
               else { 
                   last_color = value;
                   counter = 1; 
                   return std::pair<uint8_t, uint8_t>(last_color, counter); 
               }
               return std::pair<uint8_t, uint8_t>(last_color, counter); 
           });       
      
         //vec_c.erase(unique(vec_c.begin(), vec_c.end(), 
         //    [](const auto & pair1, const auto &pair2){    
         //    
         //    return pair1.first == pair2.first;
         //})
         //, vec_c.end());
        
    }
    return vec_c;
}

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale2(const std::array<std::array<uint8_t, height>, width>& bitmap)
{
    std::vector<std::pair<uint8_t, uint8_t>> vec_c;
    vec_c.reserve(width * height);
    auto last_color = bitmap[0][0];
    int counter = 0;
    int temp = 0;

    std::for_each(bitmap.begin(), bitmap.end(),
        [&vec_c, &last_color, &counter, &temp](const auto& row) {
            std::for_each(row.begin(), row.end(),
                [&vec_c, &last_color, &counter, &temp](const auto& value) {
                    if (value == last_color && temp == 0) {
                        counter++;
                    }
                    else {
                        vec_c.emplace_back(last_color, counter);
                        last_color = value;
                        counter = 1;
                        temp = 0;
                    }
                });
                temp = 1;
        });

    vec_c.emplace_back(last_color, counter);  // Dodaj ostatnią parę do vec_c

    return vec_c;
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
   
    std::vector<std::pair<uint8_t, uint8_t>> vec_c = compressGrayscale2(bitmap);

    // Sortuj wektor, aby elementy o tych samych wartościach znalazły się obok siebie
    //std::sort(vec_c.begin(), vec_c.end());

    // Usuń kolejne powtórzenia, zachowując pierwsze wystąpienie
   // auto last = std::unique(vec_c.begin(), vec_c.end(), [](const auto& a, const auto& b) {
   //     return a.first == b.first && a.second == b.second;
   // });

    // Wyświetl wynik
   // for (auto it = vec_c.begin(); it != last; ++it) {
    //    std::cout << "{" << it->first << ", " << it->second << "}, ";
  // }
 //   std::cout << std::endl;

    std::for_each(begin(vec_c), end(vec_c), [](const std::pair<uint8_t, uint8_t>& p) {
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