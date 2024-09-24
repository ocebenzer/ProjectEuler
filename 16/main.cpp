#include "bigint.hpp"
#include "iostream"

int main() {
    const auto value{ ocb::BigInt{1} << 1000 };

    auto sum{0};
    for (const auto& c : value.get()) {
        sum += c - '0';
    }

    std::cout << sum << std::endl;
}
