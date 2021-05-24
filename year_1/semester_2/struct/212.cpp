#include <iostream>
#include <cmath>
using namespace std;

struct irrationalNumber
{
  int Numerator;
  int Denominator;
};

void multiply(irrationalNumber f1, irrationalNumber f2);

int main( void ) {
  cin.clear();
  //cin.ignore();
  irrationalNumber Num1, Num2;
  cin >> Num1.Numerator >> Num1.Denominator >> Num2.Numerator >> Num2.Denominator;
  if (cin.fail()) {
    cout << "Invalid input\n";
  } else if (Num1.Denominator == 0 | Num2.Denominator == 0 | Num2.Numerator == 0) {
    cout << "Division by zero\n";
  } else if (Num1.Numerator == 0) {
    cout << "0 0\n";
  } else {
    multiply(Num1, Num2);
  };
  return 0;
};

void multiply(irrationalNumber f1, irrationalNumber f2) {
  cout << round((static_cast<float>(f1.Numerator * f2.Numerator) / (f1.Denominator * f2.Denominator)) * 100) / 100 << " " << \
              round((static_cast<float>(f1.Numerator * f2.Denominator) / (f1.Denominator * f2.Numerator)) * 100) / 100 << "\n";
};