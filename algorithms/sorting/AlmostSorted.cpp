#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

int main()
{
  int n;
  std::cin >> n;
  std::vector<int> arr(n);
  for (auto &a : arr) std::cin >> a;
  auto sorted_arr = arr;
  std::sort(begin(sorted_arr), end(sorted_arr));
  auto can_swap = true;
  auto ind_1 = -1;
  auto ind_2 = -1;
  for (auto i = 0; i < n; ++i) {
    if (arr[i] != sorted_arr[i]) {
      if (ind_1 == -1) {
        ind_1 = i;
      }
      else if (ind_2 == -1) {
        ind_2 = i;
      }
      else {
        can_swap = false;
        break;
      }
    }
  }
  if (ind_1 == -1) {
    std::cout << "yes" << std::endl;
    return 0;
  }
  if (can_swap) {
    std::cout << "yes" << std::endl;
    std::cout << "swap " << ind_1 + 1 << " " << ind_2 + 1 << std::endl;
    return 0;
  }

  auto reversed = false;
  auto can_reverse = true;
  for (auto i = ind_1; i < n - 1 && !reversed; ++i) {
    if (arr[i] > arr[i + 1]) {
      auto j = i;
      while (j < n - 1 && arr[j] > arr[j + 1]) ++j;
      ind_2 = j;
      std::reverse(begin(arr) + i, begin(arr) + j + 1);
      reversed = true;
    }
  }
  for (auto i = 0; i < n && can_reverse; ++i) can_reverse = can_reverse && arr[i] == sorted_arr[i];
  if (can_reverse) {
    std::cout << "yes" << std::endl;
    std::cout << "reverse " << ind_1 + 1 << " " << ind_2 + 1 << std::endl;
  }
  else {
    std::cout << "no" << std::endl;
  }
  return 0;
}
