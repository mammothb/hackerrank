#include <iostream>
#include <vector>

int GridSearch(
    std::vector<std::vector<int>> &grid
  , std::vector<std::vector<bool>> &seen
  , int m
  , int n
  , int i
  , int j)
{
  if (i < 0 || i >= m || j < 0 || j >= n) return 0;
  if (seen[i][j]) return 0;
  seen[i][j] = true;
  if (grid[i][j] == 0) return 0;
  return 1 +
      GridSearch(grid, seen, m, n, i    , j + 1) +
      GridSearch(grid, seen, m, n, i + 1, j + 1) +
      GridSearch(grid, seen, m, n, i + 1, j    ) +
      GridSearch(grid, seen, m, n, i + 1, j - 1) +
      GridSearch(grid, seen, m, n, i    , j - 1) +
      GridSearch(grid, seen, m, n, i - 1, j - 1) +
      GridSearch(grid, seen, m, n, i - 1, j    ) +
      GridSearch(grid, seen, m, n, i - 1, j + 1);
}

int main()
{
  auto max_area = 0;
  int m;
  int n;
  std::cin >> m;
  std::cin >> n;
  std::vector<std::vector<int>> grid(m, std::vector<int>(n, 0));
  std::vector<std::vector<bool>> seen(m, std::vector<bool>(n, false));
  for (auto &row : grid) {
    for (auto &col : row) std::cin >> col;
  }
  for (auto i = 0; i < m; ++i) {
    for (auto j = 0; j < n; ++j) {
      if (!seen[i][j]) {
        auto area = GridSearch(grid, seen, m, n, i, j);
        if (area > max_area) max_area = area;
      }
    }
  }
  std::cout << max_area << std::endl;
  return 0;
}
