// std::adjacent_difference
#include <numeric>
#include <vector>
int main()
{
    std::vector v { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 };
    std::adjacent_difference(v.begin(), v.end(), v.begin());
    // v = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2}

    std::vector w { -100, 2, 4, 8, 16, 32 };
    std::adjacent_difference(w.begin(), w.end(), w.begin());
    // w = {-100, 102, 2, 4, 8, 16}
    return 0;
}

// std::adjacent_difference oblicza różnicę pomiędzy parami sąsiadujących elementów