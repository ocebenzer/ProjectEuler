#include <iostream>
#include "bigint.hpp"

int main() {
	const auto value = ocb::BigInt::factorial(100);
	
	int sum{ 0 };
	for (const auto& digit : value.get()) {
		sum += digit - '0';
	}

	std::cout << sum << std::endl;
}
