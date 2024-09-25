#include <deque>
#include <iostream>
#include <vector>

enum class Month {
	january = 0,
	february = 1,
	march = 2,
	april = 3,
	may = 4,
	june = 5,
	july = 6,
	august = 7,
	september = 8,
	october = 9,
	november = 10,
	december = 11,
};

bool leap_year(int year) {
	if (year % 400) {
		return true;
	}
	if (year % 100) {
		return false;
	}
	if (year % 4) {
		return true;
	}
	return false;
}

int num_days(int year, Month month) {
	switch (month) {
	case Month::january:
	case Month::march:
	case Month::may:
	case Month::july:
	case Month::august:
	case Month::october:
	case Month::december:
		return 31;
	case Month::april:
	case Month::june:
	case Month::september:
	case Month::november:
		return 30;
	case Month::february:
		return 28 + leap_year(year);
	default:
		return 0;
	}
}

int main() {
	std::vector<int> month_days;

	for (int year{ 1901 }; year < 2001; ++year) {
		for (int month{ 0 }; month < 12; ++month) {
			month_days.push_back(num_days(year, static_cast<Month>(month)));
		}
	}

	int ctr{ 0 };
	int total_days{ 0 };
	for (const auto& month_day : month_days) {
		if (total_days % 7 == 6) {
			++ctr;
		}
		total_days += month_day;
	}

	std::cout << ctr << std::endl;
}
