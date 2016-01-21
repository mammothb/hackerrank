#include <algorithm>
#include <iostream>
#include <vector>

void Print(
    std::vector<int> &arr)
{
  for (auto a : arr) std::cout << a << " ";
  std::cout << std::endl;
}

int Partition(
    std::vector<int> &arr
  , int first
  , int last
  , int n)
{
  auto pivot_ind = last;
  auto store_ind = first;
  for (auto i = first; i < last; ++i) {
    if (arr[i] < arr[pivot_ind]) {
      std::iter_swap(begin(arr) + i, begin(arr) + store_ind);
      ++store_ind;
    }
  }  // i
  std::iter_swap(begin(arr) + pivot_ind, begin(arr) + store_ind);
  return store_ind;
}

void QuickSort(
    std::vector<int> &arr
  , int first
  , int last
  , int n)
{
  if (first < last) {
    auto p = Partition(arr, first, last, n);
    Print(arr);
    QuickSort(arr, first, p - 1, n);
    QuickSort(arr, p + 1, last, n);
  }
}
int main()
{
  int n;
  std::cin >> n;
  std::vector<int> arr(n);
  for (auto &a : arr) std::cin >> a;
  QuickSort(arr, 0, n - 1, n);
  return 0;
}
