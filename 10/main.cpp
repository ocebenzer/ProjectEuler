#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

int main() {
    const auto n{2'000'000};
    std::vector<int> prime_numbers;

    const auto is_prime = [&prime_numbers] (int number) {
        const auto number_sqrt{static_cast<int>(std::sqrt(number))};
        for (const auto prime : prime_numbers) {
            if (number % prime == 0) {
                return false;
            }
            if (prime > number_sqrt) {
                return true;
            }
        }
        return true;
    };

    for (int current{2}; current < n; current++) {
        if (is_prime(current)) {
            prime_numbers.push_back(current);
        }
    }

    std::cout << std::accumulate(prime_numbers.begin(), prime_numbers.end(), static_cast<long>(0)) << std::endl;
}
