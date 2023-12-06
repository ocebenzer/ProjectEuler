#include <iostream>

int main() {
    constexpr long n{100};
    constexpr long sum{n*(n+1)/2};
    constexpr long sq_sum{n*(n+1)*(2*n+1)/6};
    std::cout << sum*sum - sq_sum << std::endl;
}
