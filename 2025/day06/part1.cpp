#include <cctype>
#include <cstddef>
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

  for (size_t i = 0; i < block.size() - 1; i++) {
    bool hasDigit = false;

    for (char c : block[i]) {
      if (std::isdigit(c)) {
        hasDigit = true;
        break;
      }
    }

    if (hasDigit) {
      numbers.push_back(std::stoll(block[i]));
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
    bool isColumnEmpty = true;

    for (int row = 0; row < grid.size(); row++) {
      char c = grid[row][col];

      if (c != ' ') {
        isColumnEmpty = false;
        currentBlock[row] += c;
      }
    }

    if (isColumnEmpty && !currentBlock[0].empty()) {
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