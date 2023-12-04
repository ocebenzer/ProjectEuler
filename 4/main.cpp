#include <iostream>
#include <string>

const auto is_palindrome = [] (int n) {
    const std::string n_str{std::to_string(n)};
    for (int i{0}; i < n_str.size() / 2; i++) {
        if (n_str[i] != n_str[n_str.size()-1-i]) return false;
    }
    return true;
};

int main() {
    int highest{0};
    for (int i{999}; i > 99; i--) {
        for (int j{999}; j > 99; j--) {
            const auto m{i*j};
            if (is_palindrome(m) && m > highest) {
                highest = m;
            }
        }
    }

    std::cout << highest << std::endl;
}
