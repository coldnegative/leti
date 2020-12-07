#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;

void menu_print() {
        cout << "1. Создать массив.\n";
        cout << "2. Показать массивы.\n";
        cout << "3. Сортировка пузырьком.\n";
        cout << "4. Сортировка перемешиванием.\n";
        cout << "5. Сортировка расческой.\n";
        cout << "6. Сортировка вставками.\n";
        cout << "7. Быстрая сортировка.\n";
        cout << "8. Сортировка Шелла.\n";
        cout << "9. Найти минимальный и максимальный элементы.\n";
        cout << "10. Найти среднее арифметическое минимального и максимального элементов, а также индексы всех элементов, которые равны этому значению, и их количество.\n";
        cout << "11. Найти количество элементов меньше a.\n";
        cout << "12. Найти количество элементов больше b.\n";
        cout << "13. Проверка наличия числа x в отсортированном массиве, а также сравнение перебора и бинарного поиска.\n";
        cout << "14. Поменять 2 элемента местами.\n";
        cout << "15. Выход.\n";
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
/*
void sort_comb(int *array, int N) {
	const double k = 1.247330950103979;
	int step = N;
	while (step > 1) {
		for (int i = 0; i + step < N; i++)
			if (array[i] > array[i + step]) {
                array[i] ^= array[i + step] ^= array[i] ^= array[i + step];
            }
		step /= k;
	}
	bool b = true;
	while (b) {
		b = false;
		for (int i = 0; i + 1 < N; i++) {
			if (array[i] > array[i + step]) {
				array[i] ^= array[i + 1] ^= array[i] ^= array[i + 1];
				b = true;
			}
		}
	}
}

void sort_quick(int *array, int N) {
    if (r - l <= 1) return;
	int z = *(l + (r - l) / 2);
	int* ll = l, *rr = r - 1;
	while (ll <= rr) {
		while (*ll < z) ll++;
		while (*rr > z) rr--;
		if (ll <= rr) {
			swap(*ll, *rr);
			ll++;
			rr--;
		}
	}
	if (l < rr) sort_quick(l, rr + 1);
	if (ll < r) sort_quick(ll, r);
}

void sort_shell(int *array, int N) {
    int sz = r - l;
	int step = sz / 2;
	while (step >= 1) {
		for (int *i = l + step; i < r; i++) {
			int *j = i;
			int *diff = j - step;
			while (diff >= l && *diff > *j) {
				swap(*diff, *j);
				j = diff;
				diff = j - step;
			}
		}
		step /= 2;
	}
}
*/
void minmax(int array[], int N, bool check) {
    int min, max;
    min = max = array[0];
    for (int i = 1; i < N; i++)
        if (array[i] > max) {max = array[i];}
        else if (array[i] < min) {min = array[i];}
    if (check == 0) {
        cout << "Минимальный элемент: " << min << "\nМаксимальный элемент: " << max << "\n";
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
        for (int i = 0; i < N; i++)
            if (array[i] == X) {
                flag = true;
                break;
            }
        if (flag) {
            printf("Число %d найдено методом перебора за d секунд.\n", X);
        } else {
            printf("Число %d не найдено методом перебора за d секунд.\n", X);
        }
        flag = false;
        while ((left <= right) && (flag != true)) {
            mid = (left + right) / 2;
            if (array[mid] == X) { flag = true; }
            else if (array[mid] > X) { right = mid - 1; }
            else { left = mid + 1; };
        }
        if (flag) {
            printf("Число %d найдено бинарным поиском за d секунд.\n", X);
        } else {
            printf("Число %d не найдено бинарным поиском за d секунд.\n", X);
        }
        break;
        }
    }
}

void array_swap(int *array, int A, int B) {
    array[A] ^= array[B] ^= array[A] ^= array[B];
}

int main() {
    const int n = 10;
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
            //sort_comb(array_sorted, n);
            goto explicit_label;
        case 6:
            array_copy(array_unsorted, array_sorted, n);
            sort_insert(array_sorted, n);
            goto explicit_label;
        case 7:
            array_copy(array_unsorted, array_sorted, n);
            //sort_quick(array_sorted, n);
            goto explicit_label;
        case 8:
            array_copy(array_unsorted, array_sorted, n);
            //sort_shell(array_sorted, n);
            goto explicit_label;
        case 9:
            minmax(array_unsorted, n, 0);
            break;
        case 10:
            minmax(array_unsorted, n, 1);
            break;
        case 11:
            cout << "Введите a: ";
            cin >> a;
            array_find(array_sorted, n, a, 1);
            break;
        case 12:
            cout << "Введите b: ";
            cin >> b;
            array_find(array_sorted, n, b, 2);
            break;
        case 13:
            cout << "Введите x: ";
            cin >> x;
            array_find(array_sorted, n, x, 3);
            break;
        case 14:
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
        case 15:
            break;
        default:
            explicit_label:
            cout << "Неотсортированный массив: ";
            array_output(array_unsorted, n);
            cout << "Отсортированный массив: ";
            array_output(array_sorted, n);
            break;
        }
    } while (choice != 15);

    return 0;
}