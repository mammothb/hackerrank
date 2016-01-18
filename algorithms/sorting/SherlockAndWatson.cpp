#include <iostream>
#include <vector>

int main()
{
  int n;
  int k;
  int q;
  std::cin >> n >> k >> q;
  std::vector<int> arr(n);
  for (auto &a : arr) std::cin >> a;
  for (auto i = 0; i < q; ++i) {
    int q_no;
    std::cin >> q_no;
    std::cout << arr[(q_no - k % n + n) % n] << std::endl;
  }
  return 0;
}
