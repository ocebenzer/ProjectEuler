#include <bigint.hpp>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector bigInts {
        ocb::BigInt::factorial(9), //
        ocb::BigInt::factorial(9), //
        ocb::BigInt::factorial(8), // 2
        ocb::BigInt::factorial(8), // 2
        ocb::BigInt::factorial(8), // 2
        ocb::BigInt::factorial(8), // 2
        ocb::BigInt::factorial(8), // 2
        ocb::BigInt::factorial(8), // 2
        ocb::BigInt::factorial(7), // 27
        ocb::BigInt::factorial(7), // 27
        ocb::BigInt::factorial(7), // 27
        ocb::BigInt::factorial(7), // 27
        ocb::BigInt::factorial(7), // 27
        ocb::BigInt::factorial(7), // 27
        ocb::BigInt::factorial(6), // 278
        ocb::BigInt::factorial(6), // 278
        ocb::BigInt::factorial(5), // 2783
        ocb::BigInt::factorial(5), // 2783
        ocb::BigInt::factorial(5), // 2783
        ocb::BigInt::factorial(5), // 2783
        ocb::BigInt::factorial(5), // 2783
        ocb::BigInt::factorial(4), // 27839
        ocb::BigInt::factorial(3), // 278391
        ocb::BigInt::factorial(3), // 278391
        ocb::BigInt::factorial(2), // 2783915
        ocb::BigInt::factorial(1), // 27839154
        ocb::BigInt::factorial(0), // 278391546
    };

    const auto sum = std::accumulate(bigInts.begin(), bigInts.end(), ocb::BigInt{});

    std::cout << sum << std::endl;

}
