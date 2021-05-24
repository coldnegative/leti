#include <iostream>

using namespace std;

int main( void ) {
  int pos = 0;
  int *arr = new int [1] ();
  while (cin >> arr[pos]) {
    //cin >> arr[pos];
    
    pos++;
    arr = (int*)realloc(arr, sizeof(arr) + sizeof(int));
  };
  cout << sizeof(arr) / sizeof(int) << "\n";
  for (int i = 0; i <= pos - 1; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
  free(arr);
  return EXIT_SUCCESS;
}