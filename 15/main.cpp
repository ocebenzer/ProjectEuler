#include "bigint.hpp"
#include "iostream"

int main() {
    const auto f40{ocb::BigInt::factorial(40)};
    const auto f20{ocb::BigInt::factorial(20)};

    std::cout << f40/ (f20*f20) << std::endl;
}
