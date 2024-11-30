#include <fstream>
#include <iostream>
#include <numeric>
#include <regex>

auto parse_file(std::ifstream& file) -> std::vector<std::string> {
    std::string line;
    std::getline(file, line);
    std::stringstream ss(line);

    std::vector<std::string> names;
    for (std::string name; std::getline(ss, name, ',');) {
        names.push_back(name.substr(1, name.size() - 2));
    }

    return names;
}


int main(int argc, char const *argv[]) {
    std::ifstream file(argv[1]);
    auto names = parse_file(file);

    std::sort(names.begin(), names.end());

    std::vector<int> scores;
    for (int i = 0; i < names.size(); i++) {
        const auto& name = names[i];
        const auto name_worth = std::accumulate(name.begin(), name.end(), 0, [](const int v1, const int v2) {
            return v1 + v2 - ('A'-1);
        });
        scores.push_back(name_worth * (i+1));
    }

    const auto scores_sum = std::accumulate(scores.begin(), scores.end(), 0);
    std::cout << scores_sum << std::endl;

    return 0;
}
