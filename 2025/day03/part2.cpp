#include <fstream>
#include <iostream>
#include <string>

long long getLargestJoltage(const std::string& line) {
  std::string result;
  int currentIndex = -1;
  int needed = 12;

  while (needed) {
    int end = line.length() - needed;
    char maxChar = 0;
    int maxCharIndex = -1;

    for (int i = currentIndex + 1; i <= end; i++) {
      if (line[i] > maxChar) {
        maxChar = line[i];
        maxCharIndex = i;
      }
    }
    result += maxChar;
    currentIndex = maxCharIndex;
    needed--;
  }

  return std::stoll(result);
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