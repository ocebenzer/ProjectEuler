#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <array>

int main() {
    std::vector<std::vector<int>> grid;
    int max{-1};

    {
        std::ifstream file{"../input.txt"};
        if (!file.is_open()) {
            std::cout << "file not open" << std::endl;
            exit(1);
        }

        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss{line};
            std::vector<int> numbers;
            while(!ss.eof()) {
                int n;
                ss >> n;
                numbers.push_back(n);
            }
            grid.push_back(numbers);
        }
    }

    const auto right = [&grid] (int i, int j) {
        return std::array{
            grid.at(i).at(j),
            grid.at(i).at(j+1),
            grid.at(i).at(j+2),
            grid.at(i).at(j+3)
        };
    };
    const auto left = [&grid] (int i, int j) {
        return std::array{
            grid.at(i).at(j),
            grid.at(i+1).at(j),
            grid.at(i+2).at(j),
            grid.at(i+3).at(j)
        };
    };
    const auto diag_right = [&grid] (int i, int j) {
        return std::array{
            grid.at(i).at(j),
            grid.at(i+1).at(j+1),
            grid.at(i+2).at(j+2),
            grid.at(i+3).at(j+3)
        };
    };
    const auto diag_left = [&grid] (int i, int j) {
        return std::array{
            grid.at(i).at(j),
            grid.at(i+1).at(j-1),
            grid.at(i+2).at(j-2),
            grid.at(i+3).at(j-3)
        };
    };

    for (int i{0}; i < grid.size(); i++) {
        for (int j{0}; j < grid[0].size(); j++) {
            try {
                {
                    const auto& [n1, n2, n3, n4] = right(i, j);
                    max = std::max(max, n1*n2*n3*n4);
                }
                {
                    const auto& [n1, n2, n3, n4] = left(i, j);
                    max = std::max(max, n1*n2*n3*n4);
                }
                {
                    const auto& [n1, n2, n3, n4] = diag_right(i, j);
                    max = std::max(max, n1*n2*n3*n4);
                }
                {
                    const auto& [n1, n2, n3, n4] = diag_left(i, j);
                    max = std::max(max, n1*n2*n3*n4);
                }
            }
            catch (std::out_of_range) {
                continue;
            }
        }
    }

    std::cout << max << std::endl;
}
