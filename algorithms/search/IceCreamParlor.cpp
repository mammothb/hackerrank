#include <iostream>
#include <limits>
#include <unordered_map>

int main()
{
  int test;
  std::cin >> test;
  for (auto t = 0; t < test; ++t) {
    int m;
    int n;
    std::unordered_map<int, int> mp;
    std::cin >> m;
    std::cin >> n;
    for (auto i = 0; i < n; ++i) {
      int p;
      std::cin >> p;
      if (mp.count(p) > 0) {
        if (m - p == p) {
          std::cout << mp[p] + 1 << " " << i + 1 << std::endl;
          break;
        }
        else {
          continue;
        }
      }
      mp[p] = i;
      if (mp.count(m - p) > 0 && mp[m - p] < i) {
        std::cout << mp[m - p] + 1 << " " << i + 1 << std::endl;
        break;
      }
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  return 0;
}
