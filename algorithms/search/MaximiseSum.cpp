#include <iostream>
#include <set>

int main()
{
  int test;
  std::cin >> test;
  for (auto t = 0; t < test; ++t) {
    int n;
    int64_t m;
    std::cin >> n >> m;
    std::set<int64_t> arr_sum;
    int64_t sum = 0;
    int64_t ans = 0;
    for (auto i = 0u; i < n; ++i) {
      int64_t num;
      std::cin >> num;
      sum = (sum + num) % m;
      if (sum > ans) ans = sum;
      auto it_sum = arr_sum.upper_bound(sum);
      if (it_sum != end(arr_sum)) {
        auto temp = sum + m - *it_sum;
        if (temp > ans) ans = temp;
      }
      arr_sum.insert(sum);
    }
    std::cout << ans << std::endl;
  }
  return 0;
}
