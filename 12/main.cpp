#include <cmath>
#include <iostream>
#include <vector>
#include <set>

const auto find_divisors = [] (int n) {
    std::set<int> divisors;
    for (int i{1}; i <= std::sqrt(n); i++) {
        if (n % i == 0) {
            divisors.insert(i);
            divisors.insert(n / i);
        }
    }
    return divisors;
};

int main() {
    std::vector<int> triangle_numbers{1, 1};

    for (int i{2}; ; i++) {
        triangle_numbers.push_back(*(triangle_numbers.end()-1) + i);
        if (find_divisors(*(triangle_numbers.end()-1)).size() > 500) break;
    }

    std::cout << *(triangle_numbers.end()-1) << std::endl;
}
