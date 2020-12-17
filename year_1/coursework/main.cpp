#include <iostream>
#include <chrono>
#include <unistd.h>

using namespace std;
using namespace std::chrono;

void practice1();
void practice2();
void practice3();
//void practice4();

void main_menu_print() {
        cout << "Курсовая работа.\n\nГлавное меню:\n";
        cout << "1. Типы данных и их внутреннее представление в памяти.\n";
        cout << "2. Одномерные статические массивы.\n";
        cout << "3. Арифметика указателей и двумерные массивы.\n";
        cout << "4. Текстовые строки как массивы символов.\n";
        cout << "5. Выход.\n";
        cout << ">";
}

int main ( void ) {
    char choice;
    do {
        //system("clear");
        setlocale(LC_ALL, "Russian");
        main_menu_print();
        cin >> choice;
        switch (choice) {
        case '1':
            practice1();
            break;
        case '2':
            practice2();
            break;
        case '3':
            practice3();
            break;
        case '4':
            //practice4();
            break;
        case '5':
            break;
//        default:
        }
    } while (choice != '5');

    return 0;
}

void practice1() {
    system("clear");
    cout << "Практическая работа №1 'ТИПЫ ДАННЫХ И ИХ ВНУТРЕННЕЕ ПРЕДСТАВЛЕНИЕ В ПАМЯТИ'\n\n";
    // 1 задание
    cout << "1. Объем памяти (в байтах) для хранения данных типа:\n";
    cout << "\t- int: " << sizeof(int) << "\n" << "\t- short int: " << sizeof(short int) << "\n"\
        << "\t- long int: " << sizeof(long int) << "\n" << "\t- float: " << sizeof(float) << "\n"\
        << "\t- double: " << sizeof(double) << "\n" << "\t- long double: " << sizeof(long double) << "\n"\
        << "\t- char: " << sizeof(char) << "\n" << "\t- bool: " << sizeof(bool) << "\n\n";
    
    // 2 задание
    int value;
    unsigned int order = sizeof(int) * 8;
	unsigned int mask = 1 << order - 1; // Маска побитового сравнения
    cout << "2. Вывод на экран двоичного представления в памяти (все разряды) целого числа.\n\
Для продолжения введите целое число: ";
    cin >> value;
	for (int i = 1; i <= order; i++) {
		cout << (value & mask ? '1' : '0'); 
		value <<= 1; // Побитовый сдвиг числа
		if (i % 8 == 0)	{ cout << " ";	}
		if (i % order - 1 == 0)	{ cout << " ";	}
	}
    cout << "\n\n";

    // 3 задание
    union {
        int tool;
        float numb_f;
    };
    unsigned int order0 = sizeof(float) * 8;
	unsigned int mask0 = 1 << order0 - 1;
    cout << "3. Вывод на экран двоичного представления в памяти (все разряды) типа float.\n\
Для продолжения введите число: ";
    cin >> numb_f;
    for (int i = 1; i <= order0; i++) {
		cout << (tool & mask0 ? '1' : '0'); 
		tool <<= 1;
		if (i - 9 == 0)	{ cout << " "; }
		if (i % order0 - 1 == 0)	{ cout << " ";	}
	}
    cout << "\n\n";

    // 4 задание
    union {
        int tool_arr[2]={};
        double numb_d;
    };
    unsigned int order2 = sizeof(float) * 8;
	unsigned int mask2 = 1 << order2 - 1;
    cout << "4. Вывод на экран двоичного представления в памяти (все разряды) типа double.\n\
Для продолжения введите число: ";
    cin >> numb_d;
    for (int j = 1; j >= 0; j--) {
        for (int i = 1; i <= order2; i++) {
		    cout << (tool_arr[j] & mask2 ? '1' : '0'); 
		    tool_arr[j] <<= 1;
		    if ((i - 12 == 0) && (j == 1))	{ cout << " "; }
		    if ((i % order2 - 1 == 0) && (j == 1))	{ cout << " ";	}
	    }
    }
    cout << "\n\n";

    // Задание для защиты (12 вариант)
    int value1, shift;
    unsigned int order1 = sizeof(value1) * 8;
	unsigned int mask1 = 1 << order1 - 1; // Маска побитового сравнения
    cout << "Доп. задание: сдвиг всех битов вправо на введеное пользователем число.\n\
Для продолжения введите целое число: ";
    cin >> value1;
    cout << "Введите кол-во бит сдвига: ";
    cin >> shift;
    shift = shift % (sizeof(value1) * 8 ); // Нормализация сдвига
    // cout << shift << "\n";
    int t1, t2; // Временные переменные
    t1 = value1 >> shift; // Сдвиг влево с потерей
    t2 = value1 << (order1 - shift); // Сдвиг вправо с потерей
    value1 = t1 | t2; // Объединение
	for (int i = 1; i <= order1; i++) {
		cout << (value1 & mask1 ? '1' : '0'); 
		value1 <<= 1; // Побитовый сдвиг числа
		if (i % 8 == 0)	{ cout << " ";	}
		if (i % order1 - 1 == 0)	{ cout << " ";	}
	}

    cout << "\n\n";
}

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

void practice2() {
    system("clear");
    cout << "Практическая работа №2 'Одномерные статические массивы'\n\n";
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
}

int random_number(int N) {
    srand(time(0));
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

void practice3() {
    system("clear");
    cout << "Практическая работа №3 'Арифметика указателей и двумерные массивы'\n\n";
    sleep(1);
    system("clear");
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
    sleep(1);
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
    cout << "\n";
}