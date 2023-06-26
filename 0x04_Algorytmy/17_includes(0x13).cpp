//std::includes,  returns true if one sequence is a subsequence of another

#include <vector>
#include <iostream>
#include <algorithm>

int main () {
std::vector<int> r1 {0,1,2,3,4,5,6,7};
std::vector<int> r2 {0,1,3,5,6,8,9};
// as shown in image
std::cout << includes(begin(r1), end(r1), begin(r2)+1, begin(r2)+5) << '\n';  // true
// entire r2 in r1
std::cout << includes(begin(r1), end(r1), begin(r2), end(r2)) << '\n';  // true
}
