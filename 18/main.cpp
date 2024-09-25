#include <deque>
#include <iostream>
#include <vector>

const std::vector<std::vector<int>> values = {
    {75},
    {95, 64},
    {17, 47, 82},
    {18, 35, 87, 10},
    {20, 04, 82, 47, 65},
    {19, 01, 23, 75, 03, 34},
    {88, 02, 77, 73, 07, 63, 67},
    {99, 65, 04, 28, 06, 16, 70, 92},
    {41, 41, 26, 56, 83, 40, 80, 70, 33},
    {41, 48, 72, 33, 47, 32, 37, 16, 94, 29},
    {53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14},
    {70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57},
    {91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48},
    {63, 66, 04, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31},
    {04, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 04, 23},
};

struct path {
  int row;
  int col;
  int sum;
  std::vector<bool> path;
};

int main() {
  std::deque<path> paths{{0, 0, values[0][0]}};

  for (auto active_path{paths.front()}; active_path.row < 14;
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
