// std::set_union, std::set_intersection,
// std::set_symmetric_difference, std::set_difference
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>


int main()
{
// std::set_union
    std::vector<int> v1 { 1, 2, 5, 5, 5, 9 };
    std::vector<int> v2 { 2, 5, 7 };
    std::vector<int> v_union;
    std::set_union( v1.begin(), v1.end(),
                    v2.begin(), v2.end(),
                    std::back_inserter(v_union));
    std::copy(v_union.begin(), v_union.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
    // v_union = {1, 2, 5, 5, 5, 7, 9}

// std::set_intersection
    std::vector<int> v_intersection;
    std::set_intersection(  v1.begin(), v1.end(),
                            v2.begin(), v2.end(),
                            std::back_inserter(v_intersection));
    std::copy(v_intersection.begin(), v_intersection.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
    // v_intersection = {2, 5}

// std::set_symmetric_difference
    std::vector<int> v_symmetric_diff;
    std::set_symmetric_difference(  v1.begin(), v1.end(),
                                    v2.begin(), v2.end(),
                                    std::back_inserter(v_symmetric_diff));
    std::copy(v_symmetric_diff.begin(), v_symmetric_diff.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
    // symmetric_diff = {1, 5, 5, 7, 9}

// std::set_difference
    std::vector<int> v_diff;
    std::set_difference(v1.begin(), v1.end(),
                        v2.begin(), v2.end(),
                        std::back_inserter(v_diff));
    std::copy(v_diff.begin(), v_diff.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
    // diff = {1, 5, 5, 9}
}
