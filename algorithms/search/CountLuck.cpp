#include <iostream>
#include <vector>

auto counter = 0;
const static std::vector<int> d_x = {1, -1, 0, 0};
const static std::vector<int> d_y = {0, 0, -1, 1};

bool DepthFirstSearch(
    const std::vector<std::vector<char>> &forest
  , int n
  , int m
  , int x
  , int y
  , int pos_x = -1
  , int pos_y = -1)
{
  if (forest[x][y] == '*') return true;
  auto moves = 0;
  bool found = false;
  for (auto i = 0 ; i < 4 ; ++i) {
    auto n_x = x + d_x[i];
    auto n_y = y + d_y[i];

    if (!(n_x >= 0 && n_y >= 0 && n_x < n && n_y < m)) continue;
    if (n_x == pos_x && n_y == pos_y) continue;
    if (forest[n_x][n_y] == 'X') continue;
    if (DepthFirstSearch(forest, n, m, n_x, n_y, x, y)) found = true;
    ++moves;
  }
  if (found && moves > 1) ++counter;
  return found;
}

int main()
{
  int test;
  std::cin >> test;
  for (auto t = 0; t < test; ++t) {
    int n;
    int m;
    int k;
    int m_x;
    int m_y;
    std::cin >> n >> m;
    std::vector<std::vector<char>> forest(101, std::vector<char>(101));
    for (auto i = 0; i < n; ++i) {
      for (auto j = 0; j < m; ++j) {
        std::cin >> forest[i][j];
        if (forest[i][j] == 'M') {
          m_x = i;
          m_y = j;
        }
      }  // j
    }  // i
    std::cin >> k;
    counter = 0;
    DepthFirstSearch(forest, n, m, m_x, m_y);
    if (counter == k) {
      std::cout << "Impressed" << std::endl;
    }
    else {
      std::cout << "Oops!" << std::endl;
    }
  }
  return 0;
}
