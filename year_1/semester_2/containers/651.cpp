#include <iostream>
#include <forward_list>

using namespace std;

template <typename ForwardIterator>
void bubble_sort( ForwardIterator first, ForwardIterator last ) {
    for ( ForwardIterator sorted = first; first != last; last = sorted ) {
        sorted = first;
        for ( ForwardIterator current = first, prev = first; ++current != last; ++prev ) {
            if ( *current < *prev ) {
                iter_swap( current, prev );
                sorted = current;
            }
        }
    }
}

int main( void ) {
    int N = 0;
    cin >> N;
    if (N == 0)
        cout << "The list is empty";
    else if (cin.fail())
        cout << "Invalid input";
    else {
        forward_list<int> numbers(N);
        if ( numbers.empty() == true)
            cout << "The list is empty";
        else {
            for (auto iter = numbers.begin(); iter != numbers.end(); iter++) {
            cin >> *iter;
            if (cin.fail())
                cout << "Invalid input";
            }

            bubble_sort( begin( numbers ), end( numbers ) );
    
            for (auto iter = numbers.begin(); iter != numbers.end(); iter++)
                cout << *iter << " ";
        }   
    }
    cout << "\n";
    return EXIT_SUCCESS; 
}