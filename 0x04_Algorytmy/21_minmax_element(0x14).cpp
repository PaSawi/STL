
// std::min_element, std::max_element, std::minmax_element (work on iterators)
#include <algorithm>
#include <iostream>
#include <vector>


int main()
{
//std::min_element
    std::vector<int> v {7,9,3,5,3,2,4,1,8,0};
    // smallest in subrange (as shown in image):
    auto i_min = min_element(begin(v)+2, begin(v)+7);
    auto min = *i_min;  // int min = 2
    std::cout << "min: " << min << '\n';

    // smallest in entire vector:
    auto j_min = min_element(begin(v), end(v));
    std::cout << *j_min << '\n';  // prints '0'
    // index of smallest:
    auto arg_min = distance(begin(v), j_min);  // int arg_min = 9
    std::cout << "arg_min: " << arg_min << '\n';

    // erase at i's pos:  7935324180 
    i_min = v.erase(i_min);    // 'i_min' was set to 2, after deleting this position, the iterator points to 4       
    std::cout << *i_min << '\n';   // 793534180 
    // prints '4'                 

//std::max_element
    // largest in subrange (as shown in image):
    auto i_max = max_element(begin(v)+2, begin(v)+7);
    auto max = *i_max;  // int max = 5
    std::cout << "max: " << max << '\n';

    // largest in entire vector:
    auto j_max = max_element(begin(v), end(v));
    std::cout << *j_max << '\n';  // prints '9'
    // index of largest:
    auto argmax = distance(begin(v), j_max);  // int argmax = 1
    std::cout << "argmax: " << argmax << '\n';

    // erase at i's pos:  7935324180 
    i_max = v.erase(i_max);    //           
    std::cout << *i_max << '\n';   // 793324180 
    // prints '3'  
                    
//std::minmax_element
    std::vector<int> v2 {7,1,3,5,3,8,6,2,9,0};
    auto p = minmax_element(begin(v2)+2, begin(v2)+8);
    auto min_ = *p.first;    // int min_ = 2
    auto max_ = *p.second;   // int max_ = 8
    std::cout << "minmax_element: \n"<< min_ <<' '<< max_ << '\n';
    // swap element values                   
    std::swap(*p.first,*p.second); // => 7135386290
    // min & max in subrange (as shown in image):
    std::cout << *p.first <<' '<< *p.second << '\n';

    // min & max in entire vector:
    auto pv = minmax_element(begin(v2), end(v2));
    auto min_v = *pv.first;    // int min_v = 0

    auto max_v = *pv.second;   // int max_v = 9
    std::cout << min_v <<' '<< max_v << '\n';

    auto [i,j] = minmax_element(begin(v), end(v));  // C++17
    std::cout << *i <<' '<< *j << '\n';  // 0 9

    return 0;
}