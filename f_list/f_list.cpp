#include <forward_list>
#include <iostream>

using namespace std;
void dispFlist(forward_list<int> fl) {
  for (auto& el : fl) {
    cout << el << " ";
  }
  cout << "\n";
}
int main() {
  forward_list<int> fl{0, 1, 2, 3, 4, 5, 6};
  dispFlist(fl);
  fl.remove(3);
  dispFlist(fl);
  fl.insert_after(fl.before_begin(), 10);

  auto it = fl.before_begin();
  for (auto i = fl.begin(); i != fl.end(); ++i, ++it)
    ;
  fl.insert_after(it, 10);
  dispFlist(fl);
  // auto it2 = next((fl.begin()),3);
  auto it3 = fl.begin();
  advance(it3, 3);

  fl.insert_after(it3, 20);
  dispFlist(fl);
}