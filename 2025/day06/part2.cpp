#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

long long solveProblem(std::vector<std::string> block) {
  long long res;
  char op;

  for (char c : block.back()) {
    if (c != ' ') {
      op = c;
      break;
    }
  }

  std::vector<long long> numbers;

  for (int col = block[0].size() - 1; col >= 0; col--) {
    std::string number;
    bool hasDigit = false;

    for (int row = 0; row < block.size() - 1; row++) {
      char c = block[row][col];

      if (std::isdigit(c)) {
        number += c;
        hasDigit = true;
      }
    }

    if (hasDigit) {
      numbers.push_back(std::stoll(number));
    }
  }

  if (op == '+') {
    res = 0;
    for (long long n : numbers) {
      res += n;
    }
  } else if (op == '*') {
    res = 1;
    for (long long n : numbers) {
      res *= n;
    }
  }

  return res;
}

bool columnEmpty(std::vector<std::string> grid, int col) {
  for (int row = 0; row < grid.size(); row++) {
    if (grid[row][col] != ' ') {
      return false;
    }
  }
  return true;
}

int main(int argc, char** argv) {
  if (argc != 2) {
    return 1;
  }

  std::ifstream input(argv[1]);
  if (!input.is_open()) {
    return 1;
  }

  std::string line;
  std::vector<std::string> grid;
  int maxLen = 0;
  long long sum = 0;

  while (std::getline(input, line)) {
    if (line.length() > maxLen) {
      maxLen = line.length();
    }
    grid.push_back(line);
  }

  for (auto& str : grid) {
    if (str.length() < maxLen) {
      str.resize(maxLen, ' ');
    }
  }

  std::vector<std::string> currentBlock(grid.size(), "");

  for (int col = 0; col < maxLen; col++) {
    if (!columnEmpty(grid, col)) {
      for (int row = 0; row < grid.size(); row++) {
        char c = grid[row][col];
        currentBlock[row] += c;
      }
    } else if (!currentBlock[0].empty()) {
      sum += solveProblem(currentBlock);

      for (auto& str : currentBlock) {
        str = "";
      }
    }
  }

  if (!currentBlock[0].empty()) {
    sum += solveProblem(currentBlock);
  }

  input.close();
  std::cout << sum << std::endl;
  return 0;
}