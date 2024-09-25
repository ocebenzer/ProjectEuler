#include <deque>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

struct path {
  int row;
  int col;
  int sum;
  std::vector<bool> path;
};

int main(int argc, char* argv[]) {
  std::vector<std::vector<int>> values;

  {
    std::ifstream file(argv[1]);
    std::string line;
    while (std::getline(file, line)) {
        std::vector<int> row;
        std::stringstream ss(line);
        for (int value; ss >> value;) {
            row.push_back(value);
        }
        values.push_back(row);
    }
  }

  std::deque<path> paths{{0, 0, values[0][0]}};

  for (auto active_path{paths.front()}; active_path.row < 99;
       active_path = paths.front()) {    
    paths.pop_front();

    auto left_path = active_path.path;
    left_path.push_back(false);
    const path left_next{active_path.row + 1, active_path.col,
                         active_path.sum +
                             values[active_path.row + 1][active_path.col],
                         left_path};

    auto right_path = active_path.path;
    right_path.push_back(true);
    const path right_next{active_path.row + 1, active_path.col + 1,
                          active_path.sum +
                              values[active_path.row + 1][active_path.col + 1],
                          right_path};

    if (active_path.col == 0) {
      paths.push_back(left_next);
    }
    else {
      const auto &old_left = paths.back();
      if (old_left.sum < left_next.sum) {
        paths.pop_back();
        paths.push_back(left_next);
      }
    }
    paths.push_back(right_next);
  }

  path& max_path{paths[0]};
  for (const auto& path : paths) {
    if (max_path.sum < path.sum) {
      max_path = path;
    }
  }
  
  std::cout << max_path.sum << std::endl;

  return 0;
}
