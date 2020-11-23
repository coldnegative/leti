#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;

void menu_print() {
    cout << "1. Создать массив.\n";
    cout << "2. Отсортировать массив.\n";
    cout << "3. Найти максимум и минимум.\n";
    cout << "4. Найти среднее арифметическое максимума и минимума.\n";
    cout << "5. Найти элементы меньше a.\n";
    cout << "6. Найти элементы больше b.\n";
    cout << "7. Найти x.\n";
    cout << "8. Поменять элементы местами.\n";
    cout << "9. Выход.\n";
    cout << ">";
}

int menu_choice(int count) {
    int choice;
    cin >> choice;
        do {
            cout << "Некорректный ввод, попробуйте еще раз: ";
            cin >> choice;
        } while (0 < choice < count);
    return choice;
}

void array_create(int *array, int N) {
    srand(time(0));
    for (int i = 0; i < N; i++)
        array[i] = rand() % 199 - 99;
}

void array_output(int array[], int N) {
    for (int i = 0; i < N; i++)
        cout << array[i] << " ";
    cout << "\n";
}

void array_copy(int from[], int *to, int N) {
    for (int i = 0; i < N; ++i)
        to[i] = from[i];
}

void sort_bubble(int *array, int N) {
    for (int i=0; i < N - 1; i++)
        for (int j=0; j < N - i - 1; j++)
            if (array[j] > array[j + 1]) {
                array[j] ^= array[j + 1] ^= array[j] ^= array[j + 1];
            }
}

void sort_shaker(int *array, int N) {
    int i;
    for (i = 0; i < N;) {
        for (int j= i + 1; j < N; j++)
            if (array[j] < array[j - 1]) { array[j] ^= array[j - 1] ^= array[j] ^= array[j - 1]; }
        N--;
        for (int k = N - 1; k > i; k--)
            if (array[k] < array[k - 1]) { array[k] ^= array[k - 1] ^= array[k] ^= array[k - 1]; }
        i++; }
}

void sort_insert(int *array, int N) {
    int k, j;
    for (int i = 1; i < N; i++) {
        k = array[i];
        j = i - 1;
        while (j >=0 && array[j] > k) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = k;
    }
}

void minmax_out(int array[], int N) {
    int min, max;
    min = max = array[0];
    for (int i = 1; i < N; i++)
        if (array[i] > max) {max = array[i];}
        else if (array[i] < min) {min = array[i];}
    cout << min << " " << max << "\n";
}

void minmax_avg(int array[], int N) {
    int min, max, avg;
    min = max = array[0];
    for (int i = 1; i < N; i++)
        if (array[i] > max) {max = array[i];}
        else if (array[i] < min) {min = array[i];}
    avg = (min + max) / 2;
    cout << avg << "\n";
}

int main() {
    const int n = 10;
    int choice;
    int array_unsorted[n]={}, array_sorted[n]={};
    do {
        menu_print();
        choice = menu_choice(10);
    } while (choice != 9);


    return 0;
}