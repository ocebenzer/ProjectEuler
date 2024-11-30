#include <iostream>
#include <cmath>

const auto is_prime = [] (long n) {
    for (long i{2}; i < std::sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
};

int main() {
    const long long number{600851475143};

    long highest{0};
    for (long i{1}; i < std::sqrt(number); i++) {
        if (number % i == 0 && is_prime(i)) {
            highest = i;
        }
    }

    std::cout << highest << std::endl;
}
