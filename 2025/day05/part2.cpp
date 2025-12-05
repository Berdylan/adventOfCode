#include <algorithm>
#include <cstddef>
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

  long long count = 0;
  std::vector<std::pair<long long, long long>> ranges;
  std::vector<std::pair<long long, long long>> merged;
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

  if (ranges.empty()) {
    return 1;
  }

  std::sort(ranges.begin(), ranges.end());
  merged.push_back(ranges[0]);

  for (size_t i = 1; i < ranges.size(); i++) {
    auto& last = merged.back();
    auto current = ranges[i];

    if (current.first <= last.second) {
      if (current.second > last.second) {
        last.second = current.second;
      }
    } else {
      merged.push_back(current);
    }
  }

  for (const auto& r : merged) {
    count += r.second - r.first + 1;
  }

  input.close();
  std::cout << count << std::endl;
  return 0;
}