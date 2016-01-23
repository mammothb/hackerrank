#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

int TreeSearch(
    const std::vector<std::vector<int>> &tree
  , std::vector<int> &values
  , std::vector<bool> &seen
  , std::vector<int> &sums
  , int pos)
{
  if (seen[pos]) return 0;
  seen[pos] = true;
  if (tree[pos].size() == 1) {
    sums[pos] = values[pos];
    return sums[pos];
  }
  else {
    auto ans = values[pos];
    for (auto edge : tree[pos])
        ans += TreeSearch(tree, values, seen, sums, edge);
    sums[pos] = ans;
    return sums[pos];
  }
}

int main()
{
  int n;
  auto root = 0;
  auto total = 0;
  auto best = INT_MAX;
  std::cin >> n;
  std::vector<int> values(n);
  std::vector<int> sums(n, 0);
  std::vector<bool> seen(n, false);
  std::vector<std::vector<int>> tree(n);
  for (auto i = 0; i < n; ++i) {
    std::cin >> values[i];
    total += values[i];
  }
  for (auto i = 0; i < n - 1; ++i) {
    int a;
    int b;
    std::cin >> a >> b;
    tree[a - 1].push_back(b - 1);
    tree[b - 1].push_back(a - 1);
  }
  for (auto i = 0; i < n; ++i) {
    if (tree[i].size() > 1) {
      root = i;
      break;
    }
  }
  TreeSearch(tree, values, seen, sums, root);
  for (auto &sum : sums) sum = std::abs(total - 2 * sum);
  std::sort(begin(sums), end(sums));
  std::cout << sums[0] << std::endl;
  return 0;
}
