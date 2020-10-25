#include <iostream>
using namespace std;
int main()
{
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

    return 0;
}