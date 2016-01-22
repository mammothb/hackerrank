#include <algorithm>
#include <iostream>
#include <vector>

bool NextPermutation(
    std::string &s)
{
  auto length = s.size();
  if (length == 0) return false;
  // Find non-increasing suffix
  auto i = length - 1;
  while (i > 0 && s[i - 1] >= s[i]) --i;
  if (i == 0) return false;

  // Find successor to pivot
  auto j = length - 1;
  while (s[j] <= s[i - 1]) --j;
  std::swap(s[i - 1], s[j]);

  // Reverse suffix
  std::reverse(s.begin() + i, s.end());
  return true;
}

int main() {
  int test;
  std::cin >> test;
  while (test-- > 0) {
    std::string s;
    std::cin >> s;
    std::string ans = "no answer";
    if (NextPermutation(s)) ans = s;
    std::cout << ans << std::endl;
  }
  return 0;
}
