#include <fstream>
#include <iostream>

int main(int argc, char** argv) {
  int password = 0;
  int currentPosition = 50;
  char direction;
  int distance;

  if (argc != 2) {
    return 1;
  }

  std::ifstream input(argv[1]);
  if (!input.is_open()) {
    return 1;
  }

  while (input >> direction >> distance) {
    if (direction == 'R') {
      currentPosition = (currentPosition + distance) % 100;
    } else if (direction == 'L') {
      currentPosition = (currentPosition - distance + 100) % 100;
    }
    if (currentPosition == 0) {
      password++;
    }
    // std::cout << "Current Position: " << currentPosition << std::endl;
  }
  input.close();
  std::cout << "Password: " << password << std::endl;
  return 0;
}