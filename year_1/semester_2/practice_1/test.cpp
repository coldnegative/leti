#include <cstring>
#include <iostream>
#include <unistd.h>
#include <fstream>

#define dbName "students"

using namespace std;

struct profile {
    string full_name;
	char sex;
	int group;
	int id;
	int grades[8];
	char depart[9];
	string date;
};

void anyKey() {
	cout << "Для продолжения нажмите Enter...";
	cin.ignore();
	cin.get();
}

void menuPrint() {
    cout << "\
1. Создание новой записи о студенте.\n\
2. Внесение изменений в уже имеющуюся запись.\n\
3. Вывод всех данных о студентах.\n\
4. Вывод данных по фильтру.\n\
5. Выход.\n\
> ";
};

void showData();

int main ( void ) {
    setlocale(LC_ALL, "Russian");
    char menuSelect;
    do {
        system("clear");
        menuPrint();
        cin >> menuSelect;
        switch (menuSelect) {
            case '3':
                showData();
                break;
            case '5':
                break;
        }
    } while (menuSelect != '5');
    
    return EXIT_SUCCESS;
}

int countStudents() {
	ifstream database(dbName);
	if (database.is_open()) {
		int temp = 0;
		string data;
		while (!database.eof())
		{
			getline(database, data);
			temp++;
		}
		database.close();
		int n;
		n = temp / 7;
		return n;
	}
    else return 0;
}

void showData() {
    system("clear");
    ifstream database(dbName);
	if (!database.is_open())
		cout << "Ошибка открытия файла!";
	else {
		int temp;
		temp = countStudents(); 
		if (temp == 0)
			cout << "Файл пуст.";
		else {
			string data;
			while (!database.eof()) {
				getline(database, data);
				cout << data << '\n';
			}
		}
		database.close();
	}
	anyKey();
}