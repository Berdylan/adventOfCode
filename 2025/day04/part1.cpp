#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int countAdjacentPaper(std::vector<std::string>& grid, int r, int c,
                       int rowsSize, int colsSize) {
  int count = 0;
  int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
  int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

  for (int i = 0; i < 8; i++) {
    int nr = r + dr[i];
    int nc = c + dc[i];

    if (nr >= 0 && nr < rowsSize && nc >= 0 && nc < colsSize) {
      if (grid[nr][nc] == '@') {
        count++;
      }
    }
  }
  return count;
}

int main(int argc, char** argv) {
  if (argc != 2) {
    return 1;
  }

  std::ifstream input(argv[1]);
  if (!input.is_open()) {
    return 1;
  }

  std::vector<std::string> grid;
  std::string line;

  while (std::getline(input, line)) {
    grid.push_back(line);
  }

  int rowsSize = grid.size();
  int colsSize = grid[0].size();
  int sum = 0;

  for (int r = 0; r < rowsSize; r++) {
    for (int c = 0; c < colsSize; c++) {
      if (grid[r][c] != '@') {
        continue;
      }
      int adjacent = countAdjacentPaper(grid, r, c, rowsSize, colsSize);
      if (adjacent < 4) {
        sum++;
      }
    }
  }

  input.close();
  std::cout << sum << std::endl;
  return 0;
}