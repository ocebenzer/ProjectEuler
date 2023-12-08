#include <algorithm>
#include <iostream>
#include <array>
#include <numeric>

int main() {
    using ull = unsigned long long;

    const auto find_next = [] (ull n) {
        if (n % 2 == 0) {
            return n / 2;
        }
        return 3 * n + 1;
    };

    const ull limit{1'000'000};

    std::array<int, limit+1> sequences{0}; // index 0 is empty for convenience
    sequences[1] = 1;

    for (ull i{2}; i <= limit; i++) {
        ull num{i};
        while (num > 1) {
            ull next{find_next(num)};
            if (next < limit && sequences[next] > 0) {
                sequences[i] += sequences[next] + 1;
                num = 1;
            }
            else {
                sequences[i]++;
                num = next;
            }
        }
    }

    int max{std::reduce(sequences.begin(), sequences.end(), 0, [] (int a, int b) { return std::max(a, b); })};

    std::cout << std::find(sequences.begin(), sequences.end(), max) - sequences.begin() << std::endl;
}
