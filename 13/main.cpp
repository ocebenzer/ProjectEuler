#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <numeric>

int main() {
    std::vector<std::string> lines;

    {
        std::ifstream file{"../input.txt"};
        if (!file.is_open()) {
            std::cout << "file not open" << std::endl;
            exit(1);
        }

        std::string line;
        while (std::getline(file, line)) {
            lines.push_back(line);
        }
    }

    const auto add = [] (const std::string& s1, const std::string& s2) {
        std::stringstream ss{""};
        int remainder{0};

        const auto add_digits = [&ss, &remainder] (int n1, int n2=0) {
            const auto sum{n1 + n2 + remainder};
            remainder = sum / 10;
            ss << std::to_string(sum % 10);
        };

        for (auto itr1{s1.rbegin()}, itr2{s2.rbegin()}; itr1 != s1.rend() && itr2 != s2.rend(); itr1++, itr2++) {
            add_digits(*itr1 - '0', *itr2 - '0');
        }

        {
            auto itr{s1.rbegin() + s2.size()};
            auto itr_end{s1.rend()};

            if (s2.size() > s1.size()) {
                itr = s2.rbegin() + s1.size();
                itr_end = s2.rend();
            }

            for (; itr != itr_end; itr++) {
                add_digits(*itr - '0');
            }
        }

        if (remainder) {
            ss << remainder;
        }

        auto result{ss.str()};

        std::reverse(result.begin(), result.end());
        return result;
    };

    const auto result{std::reduce(lines.begin(), lines.end(), std::string{}, [&add] (const auto s1, const auto s2) { return add(s1, s2); })};

    std::cout << result.substr(0, 10) << std::endl;
}
