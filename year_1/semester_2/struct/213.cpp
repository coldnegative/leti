#include <iostream>
#include <cmath>

struct Complex
{
  float Real, Im;
};

int main( void ) {
  std::cin.clear();
  Complex Num[2];
  std::cin >> Num[0].Real >> Num[0].Im >> Num[1].Real >> Num[1].Im;
  if (std::cin.fail()) {
    std::cout << "Invalid input\n";
  } else {
    Complex Sum, Diff, Mult, Div;
    Sum.Real = Num[0].Real + Num[1].Real;
    Sum.Im = Num[0].Im + Num[1].Im;
    Diff.Real = Num[0].Real - Num[1].Real;
    Diff.Im = Num[0].Im - Num[1].Im;
    Mult.Real = round((Num[0].Real * Num[1].Real - Num[0].Im * Num[1].Im) * 100) / 100;
    Mult.Im = round((Num[0].Real * Num[1].Im + Num[0].Im * Num[1].Real) * 100) / 100;
    Div.Real = round(((Num[0].Real * Num[1].Real + Num[0].Im * Num[1].Im) / (pow(Num[1].Real, 2) + pow(Num[1].Im, 2))) * 100) / 100;
    Div.Im = round(((Num[0].Im * Num[1].Real - Num[0].Real * Num[1].Im) / (pow(Num[1].Real, 2) + pow(Num[1].Im, 2))) * 100) / 100;
    if (Sum.Real == 0 & Sum.Im == 0) {
        std::cout << "0\n";
    } else if (Sum.Real == 0 & Sum.Im != 0) {
        std::cout << Sum.Im << "i\n";
    } else if (Sum.Real != 0 & Sum.Im == 0) {
        std::cout << Sum.Real << "\n";
    } else if (Sum.Real != 0 & Sum.Im < 0) {
        std::cout << Sum.Real << " - " << -Sum.Im << "i\n";
    } else {
        std::cout << Sum.Real << " + " << Sum.Im << "i\n";
    };
    if (Diff.Real == 0 & Diff.Im == 0) {
        std::cout << "0\n";
    } else if (Diff.Real == 0 & Diff.Im != 0) {
        std::cout << Diff.Im << "i\n";
    } else if (Diff.Real != 0 & Diff.Im == 0) {
        std::cout << Diff.Real << "\n";
    } else if (Diff.Real != 0 & Diff.Im < 0) {
        std::cout << Diff.Real << " - " << -Diff.Im << "i\n";
    } else {
        std::cout << Diff.Real << " + " << Diff.Im << "i\n";
    };
    if (Mult.Real == 0 & Mult.Im == 0) {
        std::cout << "0\n";
    } else if (Mult.Real == 0 & Mult.Im != 0) {
        std::cout << Mult.Im << "i\n";
    } else if (Mult.Real != 0 & Mult.Im == 0) {
        std::cout << Mult.Real << "\n";
    } else if (Mult.Real != 0 & Mult.Im < 0) {
        std::cout << Mult.Real << " - " << -Mult.Im << "i\n";
    } else {
        std::cout << Mult.Real << " + " << Mult.Im << "i\n";
    };
    if (Div.Real == 0 & Div.Im == 0) {
        std::cout << "0\n";
    } else if (Div.Real == 0 & Div.Im != 0) {
        std::cout << Div.Im << "i\n";
    } else if (Div.Real != 0 & Div.Im == 0) {
        std::cout << Div.Real << "\n";
    } else if (Div.Real != 0 & Div.Im < 0) {
        std::cout << Div.Real << " - " << -Div.Im << "i\n";
    } else {
        std::cout << Div.Real << " + " << Div.Im << "i\n";
    };
  };
  return 0;
};