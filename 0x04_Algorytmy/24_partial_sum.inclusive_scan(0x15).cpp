//std::partial_sum
//std::inclusive_scan, std::exclusive_scan

#include <iostream>
#include <iterator>
#include <list>
#include <numeric>
#include <vector>

int main()
{
    std::vector<int> v = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2}; // or std::vector<int>v(10, 2);
    std::partial_sum(v.begin(),
                     v.end(),
                     std::ostream_iterator<int>(std::cout, " "));
    // output: 2 4 6 8 10 12 14 16 18 20
    
    std::partial_sum(v.begin(), v.end(), v.begin(), std::multiplies<int>());
    // v = {2, 4, 8, 16, 32, 64, 128, 256, 512, 1024}
    
    v = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2}; // or std::vector<int>v(10, 2);
    std::inclusive_scan(v.begin(), v.end(), v.begin(), std::multiplies<int>());
    // v = {2, 4, 8, 16, 32, 64, 128, 256, 512, 1024}
    
    v = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2}; // or std::vector<int>v(10, 2);
    std::exclusive_scan(v.begin(), v.end(), v.begin(), 1, std::multiplies<int>());
    // v = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512}
    std::cout << '\n';
}

//std::partial_sum oblicza sumę częściową (od początku zakresu do obecnie przetwarzanego elementu). Można dostarczyć własną funkcję zamiast standardowego sumowania.
//std::inclusive_scan robi dokładnie to samo.
//std::exclusive_scan robi dokładnie to samo, ale obecny element nie jest brany pod uwagę (obliczamy do poprzedniego elementu).