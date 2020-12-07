#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void menu_print() {
        cout << "1. Создать массив.\n";
        cout << "2. Показать массивы.\n";
        cout << "3. Сортировка пузырьком.\n";
        cout << "4. Сортировка перемешиванием.\n";
        cout << "5. Сортировка вставками.\n";
        cout << "6. Найти минимальный и максимальный элементы.\n";
        cout << "7. Найти среднее арифметическое минимального и максимального элементов, а также индексы всех элементов, которые равны этому значению, и их количество.\n";
        cout << "8. Найти количество элементов меньше a.\n";
        cout << "9. Найти количество элементов больше b.\n";
        cout << "10. Проверка наличия числа x в отсортированном массиве, а также сравнение перебора и бинарного поиска.\n";
        cout << "11. Поменять 2 элемента местами.\n";
        cout << "12. Дополнительное задание (№1).\n";
        cout << "13. Выход.\n";
        cout << ">";
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
    auto startTime = system_clock::now();
    for (int i=0; i < N - 1; i++)
        for (int j=0; j < N - i - 1; j++)
            if (array[j] > array[j + 1]) {
                array[j] ^= array[j + 1] ^= array[j] ^= array[j + 1];
            }
    auto endTime = system_clock::now();
    duration<double> elapsed = endTime - startTime;
    cout << std::fixed << "Результат сортировки пузырьком: " << elapsed.count() << " сек.\n";
}

void sort_shaker(int *array, int N) {
    int i;
    auto startTime = system_clock::now();
    for (i = 0; i < N;) {
        for (int j= i + 1; j < N; j++)
            if (array[j] < array[j - 1]) { array[j] ^= array[j - 1] ^= array[j] ^= array[j - 1]; }
        N--;
        for (int k = N - 1; k > i; k--)
            if (array[k] < array[k - 1]) { array[k] ^= array[k - 1] ^= array[k] ^= array[k - 1]; }
        i++; 
    }
    auto endTime = system_clock::now();
    duration<double> elapsed = endTime - startTime;
    cout << std::fixed << "Результат сортировки перемешиванием: " << elapsed.count() << " сек.\n";
}

void sort_insert(int *array, int N) {
    int k, j;
    auto startTime = system_clock::now();
    for (int i = 1; i < N; i++) {
        k = array[i];
        j = i - 1;
        while (j >=0 && array[j] > k) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = k;
    }
    auto endTime = system_clock::now();
    duration<double> elapsed = endTime - startTime;
    cout << std::fixed << "Результат сортировки вставками: " << elapsed.count() << " сек.\n";
}

void minmax(int array[], int N, bool check) {
    int min, max;
    min = max = array[0];
    auto startTime = system_clock::now();
    for (int i = 1; i < N; i++)
        if (array[i] > max) {max = array[i];}
        else if (array[i] < min) {min = array[i];}
    auto endTime = system_clock::now();
    duration<double> elapsed = endTime - startTime;
    if (check == 0) {
        cout << "Минимальный элемент: " << min << "\nМаксимальный элемент: " << max << "\n";
        cout << std::fixed << "Затраченное на поиск время: " << elapsed.count() << " сек.\n";
    } else {
        int avg = ((min + max) / 2), count = 0;
        cout << "Среднее арифметическое минимального и максимального элементов: " << avg << "\n";
        printf("Индексы элементов, которые равны %d: ", avg);
        for (int i = 0; i < N; i++)
            if (array[i] == avg) {
                cout << i << " ";
                count++;
            }
        printf("\n%d встречается в массиве %d раз.\n", avg, count);
    }
}

void array_find(int *array, int N, int X, int check) {
    int count = 0;
    bool flag = false;
    switch (check)
    {
    case 1:
        for (int i = N; i >= 0; i--)
            if (array[i] < X) {
                count = i + 1;
                break;
            }
        printf("Количество элементов меньше %d: %d.\n", X, count);
        break;
    case 2:
        for (int i = 0; i < N; i++)
            if (array[i] > X) {
                count = N - i;
                break;
            }
        printf("Количество элементов больше %d: %d.\n", X, count);
        break;
    case 3: {
        int left = 0, right = N - 1, mid;
        auto startTimeLin = system_clock::now();
        for (int i = 0; i < N; i++)
            if (array[i] == X) {
                flag = true;
                break;
            }
        auto endTimeLin = system_clock::now();
        duration<double> elapsedLinear = endTimeLin - startTimeLin;
        if (flag) {
            printf("Число %d найдено методом перебора за %f сек.\n", X, elapsedLinear.count());
        } else {
            printf("Число %d не найдено методом перебора за %f сек.\n", X, elapsedLinear.count());
        }
        flag = false;
        auto startTimeBin = system_clock::now();
        while ((left <= right) && (flag != true)) {
            mid = (left + right) / 2;
            if (array[mid] == X) { flag = true; }
            else if (array[mid] > X) { right = mid - 1; }
            else { left = mid + 1; };
        }
        auto endTimeBin = system_clock::now();
        duration<double> elapsedBinary = endTimeBin - startTimeBin;
        if (flag) {
            printf("Число %d найдено бинарным поиском за %f сек.\n", X, elapsedBinary.count());
        } else {
            printf("Число %d не найдено бинарным поиском за %f сек.\n", X, elapsedBinary.count());
        }
        if (elapsedLinear > elapsedBinary) {
            printf("Поиск методом перебора был быстрее на %f сек.\n", (elapsedLinear.count() - elapsedBinary.count()));
        } else if (elapsedBinary > elapsedLinear) {
            printf("Бинарный поиск был быстрее на %f сек.\n", (elapsedLinear.count() - elapsedBinary.count()));
        } else {
            cout << "Оба алгоритма поиска показали одинаковое время.\n";
        }
        break;
        }
    }
}

void array_swap(int *array, int A, int B) {
    auto startTime = system_clock::now();
    array[A] ^= array[B] ^= array[A] ^= array[B];
    auto endTime = system_clock::now();
    duration<double> elapsed = endTime - startTime;
    cout << std::fixed << "Перестановка элементов завершена за: " << elapsed.count() << " сек.\n";
}

void sort_bubble_reverse(int *array, int N) {
    for (int i = N - 1; i >= 1; i--)
        for (int j=0; j < i; j++)
            if (array[i] > array[j]) {
                array[j] ^= array[i] ^= array[j] ^= array[i];
            }
}

void additional(int *array, int N) {
    for (int i = 0;  i < N; i++)
        if (i == N -1) {array[i] += array[0];}
        else {array[i] += array[i+1];}
    cout << "Массив после преобразования (arr[i] += arr[i+1]): ";
    array_output(array, N);
    sort_bubble_reverse(array, N);
    cout << "Массив после обатной сортировки: ";
    array_output(array, N);
    for (int i = 1; i < 10; i++) {
        int count = 0;
        for (int j = 0; j < N; j++)
            if (array[j] % i == 0) {count++;}
        printf("Делятся нацело на %d: %d элементов.\n", i, count);
    }

}

int main() {
    const int n = 100;
    int choice, a = 0, b = 0, x = 0, swapA = 0, swapB = 0;
    int array_unsorted[n]={}, array_sorted[n]={};
    do {
        menu_print();
        cin >> choice;
        switch (choice) {
        case 1:
            array_create(array_unsorted, n);
            cout << "Новый неотсортированный массив: ";
            array_output(array_unsorted, n);
            break;
        case 2:
            goto explicit_label;
        case 3:
            array_copy(array_unsorted, array_sorted, n);
            sort_bubble(array_sorted, n);
            goto explicit_label;
        case 4:
            array_copy(array_unsorted, array_sorted, n);
            sort_shaker(array_sorted, n);
            goto explicit_label;
        case 5:
            array_copy(array_unsorted, array_sorted, n);
            sort_insert(array_sorted, n);
            goto explicit_label;
        case 6:
            minmax(array_unsorted, n, 0);
            break;
        case 7:
            minmax(array_unsorted, n, 1);
            break;
        case 8:
            cout << "Введите a: ";
            cin >> a;
            array_find(array_sorted, n, a, 1);
            break;
        case 9:
            cout << "Введите b: ";
            cin >> b;
            array_find(array_sorted, n, b, 2);
            break;
        case 10:
            cout << "Введите x: ";
            cin >> x;
            array_find(array_sorted, n, x, 3);
            break;
        case 11:
            cout << "Введите первый индекс: ";
            cin >> swapA;
            cout << "Введите второй индекс: ";
            cin >> swapB;
            if ((swapA >= 0) && (swapA < n) && (swapB >= 0) && (swapB < n) && (swapA != swapB)) {
                array_swap(array_unsorted, swapA, swapB);
                array_swap(array_sorted, swapA, swapB);
                goto explicit_label;
            } else if (swapA == swapB) {
                goto explicit_label;
            } else {
                cout << "Введена некорректная пара индексов.\n";
            }
            break;
        case 12:
            array_create(array_unsorted, 10);
            cout << "Новый неотсортированный массив: ";
            array_output(array_unsorted, 10);
            additional(array_unsorted, 10);
            break;
        case 13:
            break;
        default:
            explicit_label:
            cout << "Неотсортированный массив: ";
            array_output(array_unsorted, n);
            cout << "Отсортированный массив: ";
            array_output(array_sorted, n);
            break;
        }
    } while (choice != 13);

    return 0;
}