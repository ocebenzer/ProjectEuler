#include <iostream>
#include <numeric>
#include <set>
#include <vector>

int main() {
	std::vector<int> sums_of_divisors;
	for (int i = 0; i <= 10000; i++) {
		auto sum_of_divisors = 0;
		for (int j = 1; j < i; j++) {
			if (i % j == 0) {
				sum_of_divisors += j;
			}
		}
		sums_of_divisors.push_back(sum_of_divisors);
	}

	std::set<int> amicable_numbers;
	for (const auto amicable_candidate : sums_of_divisors) {
		if (amicable_candidate > sums_of_divisors.size()) continue;
		const auto mirror_amicable_candidate = sums_of_divisors[amicable_candidate];
		if (mirror_amicable_candidate > sums_of_divisors.size()) continue;
		if (amicable_candidate == mirror_amicable_candidate) continue;

		if (sums_of_divisors[mirror_amicable_candidate] == amicable_candidate) {
			amicable_numbers.insert(amicable_candidate);
		}
	}

	const auto sum_amicable_numbers = std::accumulate(amicable_numbers.begin(), amicable_numbers.end(), 0);
	std::cout << sum_amicable_numbers << std::endl;
}
