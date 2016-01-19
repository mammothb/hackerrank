#include <iostream>
#include <vector>

int main()
{
  int n;
  std::cin >> n;
  std::vector<int> numbers(n);
  std::vector<std::string> ss(n);
  std::vector<int> freq(100);
  for (auto i = 0; i < n; ++i) {
    int num;
    std::string s;
    std::cin >> numbers[i] >> s;
    ss[i] = i < n / 2 ? "-" : s;
    ++freq[numbers[i]];
  }  // i
  auto ind = 0;
  for (auto f : freq) {
    if (f != 0) {
      for (auto j = 0; j < n; ++j) {
        if (numbers[j] == ind) std::cout << ss[j] << " ";
      }  // j
    }
    ++ind;
  }  // f
  return 0;
}
