#include <fstream>
#include <iostream>
#include <string>

bool isInvalid(long long number) {
  std::string numStr = std::to_string(number);
  int length = numStr.length();

  for (int patternLen = 1; patternLen <= length / 2; patternLen++) {
    if (length % patternLen) {
      continue;
    }

    std::string pattern = numStr.substr(0, patternLen);
    bool isMatch = true;

    for (int i = patternLen; i < length; i += patternLen) {
      if (numStr.substr(i, patternLen) != pattern) {
        isMatch = false;
        break;
      }
    }
    if (isMatch) {
      return true;
    }
  }

  return false;
}

int main(int argc, char** argv) {
  if (argc != 2) {
    return 1;
  }

  std::ifstream input(argv[1]);
  if (!input.is_open()) {
    return 1;
  }

  long long sum = 0;
  long long start, end;
  char dash;

  while (input >> start >> dash >> end) {
    if (input.peek() == ',') {
      input.ignore();
    }

    for (long long i = start; i <= end; i++) {
      if (isInvalid(i)) {
        sum += i;
      }
    }
  }

  input.close();
  std::cout << sum << std::endl;
  return 0;
}