#include <iostream>
#include <regex>
#include <set>

const auto sum_of_divisors = [] (auto n)  {
    auto sum = 0;
    for (auto i = 1; i <= n/2; ++i) {
        if (n % i == 0) sum += i;
    }
    return sum;
};


int main() {
    std::vector<int> abundant_numbers;
    for (int i = 1; i <= 28123; ++i) {
        const auto sum = sum_of_divisors(i);
        if (sum > i) {
            abundant_numbers.push_back(i);
        }
    }

    std::set<int> sum_of_two_abundant_numbers;
    for (int i = 0; i < abundant_numbers.size(); ++i) {
        for (int j = 0; j < abundant_numbers.size(); ++j) {
            sum_of_two_abundant_numbers.insert(abundant_numbers[i] + abundant_numbers[j]);
        }
    }

    int sum = 0;
    for (int i = 0; i <= 28123; ++i) {
        if (!sum_of_two_abundant_numbers.contains(i)) {
            sum += i;
        }
    }

    std::cout << sum << std::endl;
    return 0;
}
