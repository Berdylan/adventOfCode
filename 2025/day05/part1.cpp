#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

int main(int argc, char** argv) {
  if (argc != 2) {
    return 1;
  }

  std::ifstream input(argv[1]);
  if (!input.is_open()) {
    return 1;
  }

  long long id;
  int count = 0;
  std::vector<std::pair<long long, long long>> ranges;
  std::string line;

  while (std::getline(input, line)) {
    if (line.empty()) {
      break;
    }

    long long start, end;
    char dash;
    std::stringstream ss(line);

    ss >> start >> dash >> end;
    ranges.push_back({start, end});
  }

  while (input >> id) {
    for (const auto& r : ranges) {
      if (id >= r.first && id <= r.second) {
        count++;
        break;
      }
    }
  }

  input.close();
  std::cout << count << std::endl;
  return 0;
}