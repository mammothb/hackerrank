#include <iostream>
#include <unordered_map>

int main()
{
  int test;
  std::cin >> test;
  for (auto t = 0; t < test; ++t) {
    int n ;
    std::cin >> n;
    std::unordered_map<int, uint64_t> mp;
    for (auto i = 0; i < n; ++i) {
      int num;
      std::cin >> num;
      ++mp[num];
    }
    uint64_t counter = 0;
    for (auto it : mp) {
      if (it.second > 1) counter += it.second * (it.second - 1);
    }
    std::cout << counter << std::endl;
  }
  return 0;
}
