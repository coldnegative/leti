#include <iostream>

using namespace std;

int main ( void ) {
    int n;
    cin >> n;
    if (cin.fail()) {
        cout << "Invalid input\n";
    } else if (n == 0) {
        cout << "The array contains no elements\n";
    } else {
        int *arr = new int[n];
    }
    return EXIT_SUCCESS;
}