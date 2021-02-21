#include <iostream>
#include <cmath>

struct IrrationalNumber
{
  int Numerator;
  int Denominator;
};

void multiply(IrrationalNumber f1, IrrationalNumber f2);

int main( void ) {
  std::cin.clear();
  //std::cin.ignore();
  IrrationalNumber Num1, Num2;
  std::cin >> Num1.Numerator >> Num1.Denominator >> Num2.Numerator >> Num2.Denominator;
  if (std::cin.fail()) {
    std::cout << "Invalid input\n";
  } else if (Num1.Denominator == 0 | Num2.Denominator == 0 | Num2.Numerator == 0) {
    std::cout << "Division by zero\n";
  } else if (Num1.Numerator == 0) {
    std::cout << "0 0\n";
  } else {
    multiply(Num1, Num2);
  };
  return 0;
};

void multiply(IrrationalNumber f1, IrrationalNumber f2) {
  std::cout << round((static_cast<float>(f1.Numerator * f2.Numerator) / (f1.Denominator * f2.Denominator)) * 100) / 100 << " " << \
              round((static_cast<float>(f1.Numerator * f2.Denominator) / (f1.Denominator * f2.Numerator)) * 100) / 100 << "\n";
};