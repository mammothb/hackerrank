#include <iostream>
#include <vector>

int main()
{
  auto mod = 101;
  int small = 10000;
  std::vector<int> arr(mod, 0);
  int n;
  int m;
  std::cin >> n;
  for (auto i = 0; i < n; ++i) {
    int num;
    std::cin >> num;
    --arr[num % mod];
  }
  std::cin >> m;
  for (auto i = 0; i < m; ++i) {
    int num;
    std::cin >> num;
    if (num < small) small = num;
    ++arr[num % mod];
  }
  auto start_ind = small % mod;
  for (auto i = start_ind; i != start_ind - 1; i = (i + 1) % mod) {
    if (arr[i] != 0) std::cout << small << " ";
    ++small;
  }
  return 0;
}
