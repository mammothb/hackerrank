#include <iostream>
#include <vector>

int main()
{
  int test;
  std::cin >> test;
  for (auto t = 0; t < test; ++t) {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    uint64_t r_sum = 0;
    uint64_t l_sum = 0;
    std::string ans = "NO";
    for (auto &a : arr) {
      std::cin >> a;
      r_sum += a;
    }  // a
    r_sum -= arr[0];
    for (auto i = 1; i < n; ++i) {
      l_sum += arr[i - 1];
      r_sum -= arr[i];
      if (l_sum == r_sum) {
        ans = "YES";
        break;
      }
    }  // i
    if (n == 1) ans = "YES";
    std::cout << ans << std::endl;
  }
  return 0;
}
