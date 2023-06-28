//std::transform_reduce (C++17), std::inner_product = std::transform_reduce
#include <numeric>
#include <vector>
#include <iostream>
int main()
{
    std::vector<int> a{0, 1, 2, 3, 4};
    std::vector<int> b{5, 4, 2, 3, 1};

    int r = std::transform_reduce(a.begin(), a.end(), b.begin(), 0);
    int r1 = std::transform_reduce(a.begin(), a.end(), b.begin(), 0,
                                   std::plus<>(), std::equal_to<>());
    
    int r2 = std::inner_product(a.begin(), a.end(), b.begin(), 0);
    // 0 x 5 + 1 x 4 + 2 x 2 + 3 x 3 + 4 x 1
    // r1 = 21

    int r3 = std::inner_product(a.begin(), a.end(), b.begin(), 0,
                                std::plus<>(), std::equal_to<>());
    // (0 == 5) + (1 == 4) + (2 == 2) + (3 == 3) + (4 == 1)
    // r2 = 2



    std::vector<int> v {3,2,4};
    auto f = [](int x) { return x*x; };
    auto const rf = transform_reduce(begin(v), end(v), 1, std::plus<>{}, f);  
    // rf = 1 + f(3) + f(2) + f(4) = 30
    std::cout << "rf: " << rf << '\n';

    std::vector<double> x {1.0, 3.0, 5.0};
    std::vector<double> y {2.0, 4.0, 8.0};
    auto const rx1 = transform_reduce(begin(x), end(x), begin(y), 10.0);  
    // rx1 = 10 + (1*2)+(3*4)+(5*8) = 64
    std::cout << "rx1: " << rx1 << '\n';
    auto const rx2 = transform_reduce(
        begin(x), end(x), begin(y), 0.0, 
        std::plus<>{}, std::divides<>{});  
    // Both operations ⊕ and ⊗ must be associative and commutative because there is no guaranteed order in which they are applied.
    // rx2 = 0.0 + (1/2)+(3/4)+(5/8) = 1.875
    std::cout << "rx2: " << rx2 << '\n';
    return 0;
}

//std::inner_product oblicza iloczyn skalarny 2 zakresów. Można dostarczyć własne operacja zamiast standardowych (op1 - sumowanie i op2 - mnożenie)
//std::transform_reduce robi to samo, ale można go używać współbieżnie. Wymaga, aby obie operacje były przemienne i łączne.