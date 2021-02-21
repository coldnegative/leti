#include <iostream>
#include <cmath>

struct Advertising
{
  int Count;
  float Percent;
  float Value;
};

int main( void ) {
  std::cin.clear();
  Advertising Ad;
  std::cin >> Ad.Count >> Ad.Percent >> Ad.Value;
  if (std::cin.fail()) {
    std::cout << "Invalid input\n";
  } else if (Ad.Count == 0 | Ad.Percent == 0 | Ad.Value == 0) {
    std::cout << "0.0\n";
  } else {
    std::cout << round(static_cast<float>(Ad.Count * (Ad.Percent / 100) * Ad.Value) * 100) / 100 << "\n";
  };
  return 0;
};