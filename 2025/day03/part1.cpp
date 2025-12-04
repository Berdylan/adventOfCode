#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>

long long getLargestJoltage(const std::string& line) {
  for (char c = '9'; c >= '0'; c--) {
    size_t index = line.find(c);

    if (index != std::string::npos && index < line.size() - 1) {
      int tens = c - '0';
      int ones = -1;

      for (size_t i = index + 1; i < line.size(); i++) {
        if ((line[i] - '0') > ones) {
          ones = line[i] - '0';
        }
      }
      return (tens * 10) + ones;
    }
  }
  return -1;
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
  long long sum = 0;

  while (std::getline(input, line)) {
    sum += getLargestJoltage(line);
  }

  input.close();
  std::cout << sum << std::endl;
  return 0;
}