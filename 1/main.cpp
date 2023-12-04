#include <iostream>

const auto sum_sequence = [] (int n) { return n * (n + 1) / 2; };

int main() {
    const auto to{999};
    auto sum{0};
    sum += 3 * sum_sequence(to/3);
    sum += 5 * sum_sequence(to/5);
    sum -= 15 * sum_sequence(to/15);
    std::cout << sum << std::endl;
}
