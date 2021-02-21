#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void menu_print() {
        cout << "1. Ввести текст.\n";
        cout << "2. Считать текст из файла.\n";
        cout << "3. Выход.\n";
        cout << ">";
}

int str_len(char *str) {
    unsigned int L = 0;
    while (str[L])
        ++L;
    return L;
}

void get_text(char *str, int N) {
    cin.sync();
    cout.flush();
    cin.getline(str, N, '.');
}

bool get_text_file(char *file, char *str, int N) {
    cin.sync();
    cout.flush();
    ifstream in;
    in.open(file);
    if ( !in.is_open () ) {
        cout << "Открыть файл не удалось!\n";
        in.close();
        return 0;
    } else {
        in.getline(str, N, '.');
        in.close();
        return 1;
    }
}

void str_del(int i, char *str) {
    for (i; i <= str_len(str); i++) {
        str[i] = str[i + 1];
    }
}

int search_linear(char *sub, char *str)  
{  
	for (int i = 0; str[i]; ++i) {
		for (int j = 0; ; ++j) {
			if (!sub[j]) return i;
			if(str[i+j] != sub[j]) break;
		}
	}
	return -1;
}
/*
int *pre_kmp(string pattern)
{
    int size = pattern.size();
    int *pi = new int[size];
    pi[0] = 0;
    int k = 0;
    for (int i = 1; i < size; i++)
    {
        while (k > 0 && pattern[k] != pattern[i])
        {
            k = pi[k - 1];
        }
        if (pattern[k] == pattern[i])
        {
            k = k + 1;
        }
        pi[i] = k;
    }

    return pi;
}

void kmp(string text, string pattern)
{
    int* pi = pre_kmp(pattern);
    int match = 0;
    cout << "Индексы: ";
    for (int current = 0; current < text.length(); current++)
    {
        while (match > 0 && pattern[match] != text[current])
            match = pi[match - 1];

        if (pattern[match] == text[current])
            match = match + 1;

        if (match == (pattern.length()))
        {
            cout << current - (pattern.length() - 1) << " ";
            match = pi[match - 1];
        }
    }
}
*/
int main( void ) {
    setlocale(LC_ALL, "Russian");
    const int n = 1000;
    
    char text_edited[n]={}, choice, substring[n]={};
    char filename[n];
    
    do {
        char *text_source = new char [n];
        cin.sync();
        cout.flush();
        menu_print();
        cin >> choice;
        switch (choice) {
        case '1':
            cout << "Введите текст: ";
            get_text(text_source, n);
            goto explicit_label;
        case '2':
            cout << "Введите имя файла: ";
            cin >> filename;
            if (get_text_file(filename, text_source, n) == 0) {
                break;
            } else {
                goto explicit_label;
            }
        case '3': break;
        default:
            explicit_label:

            for (int i = 0; i < str_len(text_source) - 1; i++)
                if (text_source[i] == ' ' ||
                    text_source[i] == ',' ||
                    text_source[i] == ':' ||
                    text_source[i] == ';' ||
                    text_source[i] == '?' ||
                    text_source[i] == '!') {
                        if (text_source[i + 1] == text_source[i]) {
                            str_del(i + 1, text_source);
                            i--;
                        }
                }
            
            text_source[str_len(text_source)] = '.';
            cout.flush();
            for (int i = 0; i < str_len(text_source); i++)
                cout << text_source[i];
            cout << "\nПодстрока для поиска: ";
            cin >> substring;
            auto startTime = chrono::high_resolution_clock::now();
            int pos = search_linear(substring, text_source);
            auto endTime = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed = endTime - startTime;
            if (pos == -1) {
                cout << "Подстрока не найдена.\n";
            } else {
                cout << "Подстрока найдена, позиция: " << pos << "\n";
            }
            cout << std::fixed << "Линейный поиск: " << elapsed.count() << " сек.\n";
/*
            auto startTime = chrono::high_resolution_clock::now();
            //search_kmp(a, sub);
            auto endTime = chrono::high_resolution_clock::now();
            chrono::duration<float> elapsed = endTime - startTime;
            cout.precision(7);
            cout << std::fixed << "КМП: " << elapsed.count() << " сек.\n";
*/
            delete [] text_source;
            break;
        }
    } while (choice != '3');

    return 0;
}