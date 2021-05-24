#include <iostream>
#include <array>

using namespace std;

int main( void ) {
    array<int, 10> numbers = {};
    for (int i = 0; i < numbers.size(); i++) {
        cin >> numbers[i];
        if (cin.fail())
            cout << "Invalid input";
    }

    for (int i = 0; i < numbers.size(); i++) {
        int count = 0;
        for (int j=0; j < numbers.size() - 1; j++)
            if (numbers[j] > numbers[j + 1]) {
                swap(numbers[j], numbers[j + 1]);
                count++;
            }
        if (count == 0)
            break;
    }
    
    for (int i = 0; i < numbers.size(); i++)
        cout << numbers[i] << " ";
    cout << "\n";
    return EXIT_SUCCESS; 
}