#include <iostream>
#include <unordered_map>

int Pairs(
    const std::unordered_map<int, int> &mp
  , int k) {
  auto ans = 0;
  for (auto m : mp) {
    auto int_pair = m.first + k;
    if (mp.count(int_pair) == 1) ++ans;
  }
  return ans;
}

int main() {
    int n;
    int k;
    std::cin >> n >> k;
    std::unordered_map<int, int> mp;
    for (auto i = 0; i < n; ++i) {
      int num;
      std::cin >> num;
      ++mp[num];
    }

    auto ans = Pairs(mp, k);
    std::cout << ans << std::endl;

    return 0;
}
