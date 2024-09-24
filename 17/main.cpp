#include <iostream>
#include <string_view>
#include <vector>

const auto values = [] {
  std::vector<std::string> values = {
      "",         "one",      "two",      "three",    "four",    "five",
      "six",      "seven",    "eight",    "nine",     "ten",     "eleven",
      "twelve",   "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
      "eighteen", "nineteen", "twenty"};

  std::vector<std::string> tens = {"",       "",      "twenty", "thirty",
                                   "forty",  "fifty", "sixty",  "seventy",
                                   "eighty", "ninety"};

  for (int i{21}; i < 100; ++i) {
    values.push_back(tens[i / 10] + values[i % 10]);
  }

  for (int i{100}; i < 1000; ++i) {
    values.push_back(values[i / 100] + "hundred" + (i % 100 ? ("and" + values[i % 100]) : ""));
  }

  values.push_back("one" "thousand");
  return values;
}();

int main() {
  auto sum{0};

  for (const std::string_view value : values) {
    sum += value.length();
  }

  std::cout << sum << std::endl;
}
