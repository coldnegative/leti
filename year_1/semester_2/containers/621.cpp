#include <iostream>
#include <array>

using namespace std;

int main( void ) {
    std::array<int, 10> numbers = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int count = 0;
    cin >> count;
    if (cin.fail() || count < 1)
        cout << "Invalid input";
    else if (count > 10)
        count = 10;
    for (int i = 0; i < count; i++)
        cout << numbers[i] << " ";
    cout << "\n";
    return EXIT_SUCCESS; 
}