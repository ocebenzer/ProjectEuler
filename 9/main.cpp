#include <iostream>

int main() {
    const int result{[] () { // I had to
        int a, b, c;

        for (c = 1000; c >= 0; c--) {
            for (b = c-1; b >= 0; b--) {
                a = 1000 - b - c;
                if (a < 0) continue;
                if (a > b) continue;
                if (a*a + b*b == c*c) {
                    return(a * b * c);
                }
            }
        }

        return -1;
    }()};

    std::cout << result << std::endl;
}
