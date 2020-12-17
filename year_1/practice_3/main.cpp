#include <iostream>
#include <unistd.h>

using namespace std;

int random_number(int N) {
    return rand() % (N*N - 1);
}

void matrix_print(int *matrix, int N, int *end) {
    for (int *ptr = matrix, i = 1; ptr <= end; ptr++, i++) {
        cout << *ptr << " ";
        if (i % N == 0) {
            cout << "\n";
        }
    }
}

void matrix_fill_zero(int *matrix, int *end) {
    for (int *ptr = matrix; ptr <= end; ptr++)
            *ptr = 0;
}

int main(void) {
    system("clear");
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    const int n = 6;
    int matrix[n][n] = {};
    int *end = matrix[0] + n*n - 1;
    int k=0;

    int counter = 0, i = 0, j = 0;
    while (counter < n*n) {
        *(matrix[i] + j) = random_number(n);
        if (i <= j + 1 && i + j < n - 1)
            j++;
        else if (i < j && i + j >= n - 1)
            i++;
        else if (i >= j && i + j > n - 1)
            j--;
        else
            i--;
        counter++;
        matrix_print((int *)matrix, n, end);
        cout.flush();
        sleep(1);
        system("clear");
    }

    matrix_fill_zero((int *)matrix, end);

    counter = 0, i = 0, j = 0;
    while (counter < n*n) {
        *(matrix[i] + j) = random_number(n);
        if (j % 2 == 0 && i < n - 1)
            i++;
        else if (j % 2 != 0 && i > 0)
            i--;
        else
            j++;
        counter++;
        matrix_print((int *)matrix, n, end);
        cout.flush();
        sleep(1);
        system("clear");
    }
    cout << "Исходная матрица:\n";
    matrix_print((int *)matrix, n, end);
    cout << "Результат сдвига четвертей по часовой стрелке:\n";
    sleep(1);
    for (int i = 0; i < n / 2; i++)
        for (int j = 0; j < n / 2; j++)
            *(matrix[i] + j) ^= *(matrix[i] + j + n / 2) ^= *(matrix[i] + j) ^= *(matrix[i] + j + n / 2);
    for (int i = 0; i < n / 2; i++)
        for (int j = 0; j < n / 2; j++)
            *(matrix[i] + j) ^= *(matrix[i + n / 2] + j + n / 2) ^= *(matrix[i] + j) ^= *(matrix[i + n / 2] + j + n / 2);
    for (int i = 0; i < n / 2; i++)
        for (int j = 0; j < n / 2; j++)
            *(matrix[i] + j) ^= *(matrix[i + n / 2] + j) ^= *(matrix[i] + j) ^= *(matrix[i + n / 2] + j);

    matrix_print((int *)matrix, n, end);
    cout << "Результат сдвига четвертей по диагоналям:\n";
    sleep(1);
    for (int i = 0; i < n / 2; i++)
        for (int j = 0; j < n / 2; j++)
            *(matrix[i] + j) ^= *(matrix[i + n / 2] + j + n / 2) ^= *(matrix[i] + j) ^= *(matrix[i + n / 2] + j + n / 2);
    for (int i = n / 2; i < n; i++)
        for (int j = 0; j < n / 2; j++)
            *(matrix[i] + j) ^= *(matrix[i - n / 2] + j + n / 2) ^= *(matrix[i] + j) ^= *(matrix[i - n / 2] + j + n / 2);

    matrix_print((int *)matrix, n, end);
    cout << "Результат сдвига четвертей по горизонтали:\n";
    sleep(1);
    for (int i = 0; i < n / 2; i++)
        for (int j = 0; j < n / 2; j++)
            *(matrix[i] + j) ^= *(matrix[i + n / 2] + j) ^= *(matrix[i] + j) ^= *(matrix[i  + n / 2] + j);
    for (int i = n / 2; i < n; i++)
        for (int j = n / 2; j < n; j++)
            *(matrix[i] + j) ^= *(matrix[i - n / 2] + j) ^= *(matrix[i] + j) ^= *(matrix[i - n / 2] + j);
    matrix_print((int *)matrix, n, end);
    cout << "Результат сдвига четвертей по вертикали:\n";
    sleep(1);
    for (int i = 0; i < n / 2; i++)
        for (int j = 0; j < n / 2; j++)
            *(matrix[i] + j) ^= *(matrix[i] + j + n / 2) ^= *(matrix[i] + j) ^= *(matrix[i] + j + n / 2);
    for (int i = n / 2; i < n; i++)
        for (int j = n / 2; j < n; j++)
            *(matrix[i] + j) ^= *(matrix[i] + j - n / 2) ^= *(matrix[i] + j) ^= *(matrix[i] + j - n / 2);
    matrix_print((int *)matrix, n, end);
    cout << "Результат сортировки матрицы:\n";
    sleep(1);
    for (int *p1 = matrix[0]; p1 <= end; p1++) {
        for (int *p2 = matrix[0]; p2 < end; p2++) {
            if (*p2 > *(p2 + 1)) {
                *p2 ^= *(p2 + 1) ^= *p2 ^= *(p2 + 1);
            }
        }
    }
    sleep(1);
    matrix_print((int *)matrix, n, end);
    cout << "Введите множитель: ";
    cin >> k;
    for (int *ptr = matrix[0]; ptr <= end; ptr++)
        *ptr = *ptr * k;
    matrix_print((int *)matrix, n, end);
    return 0;
}