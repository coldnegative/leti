#include <iostream>

using namespace std;

struct departureTime {
    short unsigned int hour;
    const char delimiter = ':';
    short unsigned int minute;
};

struct train
{
 string destName;
 int trainNumber;
 //departureTime depTime;
 short unsigned int hour;
 char delimiter = ':';
 short unsigned int minute;
};

int main ( void ) {
    const short unsigned int n = 10;
    train trainList[n];
    cin.clear();
    for (int i = 0; i < 10; i++) {
        cin >> trainList[i].destName >> trainList[i].trainNumber >> trainList[i].hour >> trainList[i].delimiter >> trainList[i].minute;
        if (cin.fail() || trainList->hour > 24 || trainList->minute>60) {
            cout << "Invalid input\n";
        }
    }
    for (int i = 0; i < 10; i++) {
        cout << trainList[i].destName << trainList[i].trainNumber << trainList[i].hour << ":" << trainList[i].minute << "\n";
    }
    return EXIT_SUCCESS;
}