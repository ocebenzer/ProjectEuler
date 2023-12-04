#include <iostream>

int main() {
    long number{1};

    const auto mul_times = [&number] (int mul, int times=1) {
        for (int i{0}; i < times; i++) {
            number *= mul;
        }
    };

    mul_times(2, 4);
    mul_times(3, 2);
    mul_times(5);
    mul_times(7);
    mul_times(11);
    mul_times(13);
    mul_times(17);
    mul_times(19);

    std::cout << number << std::endl;
}
