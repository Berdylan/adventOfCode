#include <fstream>
#include <iostream>
#include <string>

bool isInvalid(long long number) {
  std::string numStr = std::to_string(number);
  int length = numStr.length();
  int halfLength = length / 2;

  if (length % 2) {
    return false;
  }

  for (int i = 0; i < halfLength; i++) {
    if (numStr[i] != numStr[i + halfLength]) {
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