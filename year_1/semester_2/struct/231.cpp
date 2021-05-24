#include <iostream>
#include <cmath>

using namespace std;

struct Complex
{
  float Real, Im;
};

void complexPrint( struct Complex &complex ) {
    if (complex.Real == 0 & complex.Im == 0) {
        cout << "0\n";
    } else if (complex.Real == 0) {
        cout << complex.Im << "\n";
    } else if (complex.Im == 0) {
        cout << complex.Real << "i\n";
    } else {
        if (complex.Im > 0) {
            cout << complex.Real << " + " << complex.Im << "i\n";
        } else {
            cout << complex.Real << " - " << -complex.Im << "i\n";
        };
    };
};

int main( void ) {
  cin.clear();
  Complex Num[2];
  cin >> Num[0].Real >> Num[0].Im >> Num[1].Real >> Num[1].Im;
  if (cin.fail()) {
    cout << "Invalid input\n";
  } else {
    cout << "complex_1: ";
    complexPrint(Num[0]);
    cout << "complex_2: ";
    complexPrint(Num[1]);
    Complex Sum, Diff, Mult, Div;
    Sum.Real = Num[0].Real + Num[1].Real;
    Sum.Im = Num[0].Im + Num[1].Im;
    cout << "addition: ";
    complexPrint(Sum);
    Diff.Real = Num[0].Real - Num[1].Real;
    Diff.Im = Num[0].Im - Num[1].Im;
    cout << "subtraction: ";
    complexPrint(Diff);
    Mult.Real = round((Num[0].Real * Num[1].Real - Num[0].Im * Num[1].Im) * 100) / 100;
    Mult.Im = round((Num[0].Real * Num[1].Im + Num[0].Im * Num[1].Real) * 100) / 100;
    cout << "product: ";
    complexPrint(Mult);
    Div.Real = round(((Num[0].Real * Num[1].Real + Num[0].Im * Num[1].Im) / (pow(Num[1].Real, 2) + pow(Num[1].Im, 2))) * 100) / 100;
    Div.Im = round(((Num[0].Im * Num[1].Real - Num[0].Real * Num[1].Im) / (pow(Num[1].Real, 2) + pow(Num[1].Im, 2))) * 100) / 100;
    cout << "quotient: ";
    complexPrint(Div);
  };
  return EXIT_SUCCESS;
};