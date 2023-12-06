#include <iostream>
#include <vector>

int main() {
    const auto n{10'001};
    std::vector<int> prime_numbers;

    const auto is_prime = [&prime_numbers] (int number) {
        for (const auto prime : prime_numbers) {
            if (number % prime == 0) {
                return false;
            }
        }
        return true;
    };


    for (int current{2}; prime_numbers.size() < n; current++) {
        if (is_prime(current)) {
            prime_numbers.push_back(current);
        }
    }

    std::cout << *(prime_numbers.end() - 1) << std::endl;
}
