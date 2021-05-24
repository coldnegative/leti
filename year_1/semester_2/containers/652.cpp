#include <iostream>
#include <list>

using namespace std;

int main( void ) {
    int N = 0;
    cin >> N;
    if (N == 0)
        cout << "The list is empty";
    else if (cin.fail())
        cout << "Invalid input";
    else {
        list<int> numbers(N);
        for (auto iter = numbers.begin(); iter != numbers.end(); iter++) {
            cin >> *iter;
            if (cin.fail())
                cout << "Invalid input";
            }

        for (list<int>::reverse_iterator iter = numbers.rbegin(); iter != numbers.rend();) {
            cout << *iter << "\n";
        }
 
        for (auto iter = numbers.begin(); iter != numbers.end(); iter++)
            cout << *iter << " ";
    }
    cout << "\n";
    return EXIT_SUCCESS; 
}