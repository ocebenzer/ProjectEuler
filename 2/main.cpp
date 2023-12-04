#include <iostream>

int main() {
    unsigned long long sum{0};

    int n1{1};
    int n2{1};
    while (n2 < 4'000'000) {
        int n3{n1 + n2};
        if (n3 % 2 == 0) {
            sum += n3;
        }

        n1 = n2;
        n2 = n3;
    }

    std::cout << sum << std::endl;
}
