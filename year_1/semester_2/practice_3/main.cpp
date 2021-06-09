#include <iostream>
#include <stack>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

int getPriority(char C)
{
	if (C == '+') {
		return 1;
	}
	else if (C == '-') {
		return 2;
	}
	else if (C == '*' || C == '/')
		return 3;
	return 0;
}

char generateOperator() {
	int num = rand() % 3;
	switch(num) {
	case 0:
		return '+';
	case 1:
		return '-';
	case 2:
		return '*';
	}
}

string infixToPostfix(string in_line)
{
	in_line = '(' + in_line + ')';
	int l = in_line.size();
	stack<char> operators;
	string output;
	for (int i = 0; i < l; i++) {
		if (in_line[i] >= '0' && in_line[i] <= '9')//если цифра
			output += in_line[i];
		else if (in_line[i] == '(')
			operators.push('(');
		else if (in_line[i] == ')') {
			while (operators.top() != '(') {
				output += operators.top();
				operators.pop();
			}
			operators.pop();
		}
		else//если оператор
		{
			while (getPriority(in_line[i]) <= getPriority(operators.top()))
			{
				output += operators.top();
				operators.pop();
			}
			operators.push(in_line[i]);
		}
	}
	return output;
}

string infixToPostfixFile(string in_line, ofstream *file) {
	in_line = '(' + in_line + ')';
	int l = in_line.size();
	stack<char> operators;
	string output;
	for (int i = 0; i < l; i++) {
		if (in_line[i] >= '0' && in_line[i] <= '9') {//если цифра
			output += in_line[i];
			*file << output << '\n';
		}
		else if (in_line[i] == '(') {
			operators.push('(');
		}
		else if (in_line[i] == ')') {
			while (operators.top() != '(') {
				output += operators.top();
				*file << output << '\n';
				operators.pop();
			}
			operators.pop();
		}
		else//если оператор
		{
			while (getPriority(in_line[i]) <= getPriority(operators.top()))
			{
				output += operators.top();
				*file << output << '\n';
				operators.pop();
			}
			operators.push(in_line[i]);
		}
	}
	return output;
}

string infixToPrefix(string infix)
{
	int l = infix.size();
	reverse(infix.begin(), infix.end());
	for (int i = 0; i < l; i++) {
		if (infix[i] == '(') {
			infix[i] = ')';
			i++;
		}
		else if (infix[i] == ')') {
			infix[i] = '(';
			i++;
		}
	}
	string prefix = infixToPostfix(infix);
	reverse(prefix.begin(), prefix.end());
	return prefix;
}

string infixToPrefixFile(string infix, ofstream *file) {
	int l = infix.size();
	reverse(infix.begin(), infix.end());
	for (int i = 0; i < l; i++) {
		if (infix[i] == '(') {
			infix[i] = ')';
			i++;
		}
		else if (infix[i] == ')') {
			infix[i] = '(';
			i++;
		}
	}
	string prefix = infixToPostfix(infix);
	reverse(prefix.begin(), prefix.end());
	*file << prefix << '\n';
	return prefix;
}

int calculatePostfix(string in_line) {
	stack<int> counters;
	for (int i = 0; i < in_line.length(); i++) {
		if (in_line[i] >= '0' && in_line[i] <= '9') {
			counters.push(in_line[i] - '0');
		}
		else {
			int op2 = counters.top();
			counters.pop();
			int op1 = counters.top();
			counters.pop();
			switch (in_line[i]){
			case '+':
				counters.push(op1 + op2);
				break;
			case '-':
				counters.push(op1 - op2);
				break;
			case '*':
				counters.push(op1 * op2);
				break;
			case '/':
				counters.push(op1 / op2);
				break;
			}
		}

	}
	return counters.top();
}

int calculatePostfixFile(string in_line, ofstream *file) {
	stack<int> counters;
	for (int i = 0; i < in_line.length(); i++) {
		if (in_line[i] >= '0' && in_line[i] <= '9') {
			counters.push(in_line[i] - '0');
		}
		else {
			int op2 = counters.top();
			counters.pop();
			int op1 = counters.top();
			counters.pop();
			switch (in_line[i]) {
			case '+':
				counters.push(op1 + op2);
				*file << to_string(op1) << " + " << to_string(op2) << " = " << to_string(counters.top()) << '\n';
				break;
			case '-':
				counters.push(op1 - op2);
				*file << to_string(op1) << " - " << to_string(op2) << " = " << to_string(counters.top()) << '\n';
				break;
			case '*':
				counters.push(op1 * op2);
				*file << to_string(op1) << " * " << to_string(op2) << " = " << to_string(counters.top()) << '\n';
				break;
			case '/':
				counters.push(op1 / op2);
				*file << to_string(op1) << " / " << to_string(op2) << " = " << to_string(counters.top()) << '\n';
				break;
			}
		}

	}
	*file << '\n';
	return counters.top();
}

int calculatePrefix(string in_line){
	stack<int> counters;
	for (int i = in_line.size() - 1; i >= 0; i--) {
		if (in_line[i] >= '0' && in_line[i] <= '9')
			counters.push(in_line[i] - '0');
		else {
			int op1 = counters.top();
			counters.pop();
			int op2 = counters.top();
			counters.pop();
			switch (in_line[i]) {
			case '+':
				counters.push(op1 + op2);
				break;
			case '-':
				counters.push(op1 - op2);
				break;
			case '*':
				counters.push(op1 * op2);
				break;
			case '/':
				counters.push(op1 / op2);
				break;
			}
		}
	}
	return counters.top();
}

int calculatePrefixFile(string in_line, ofstream *file) {
	stack<int> counters;
	for (int i = in_line.size() - 1; i >= 0; i--) {
		if (in_line[i] >= '0' && in_line[i] <= '9')
			counters.push(in_line[i] - '0');
		else {
			int op1 = counters.top();
			counters.pop();
			int op2 = counters.top();
			counters.pop();
			switch (in_line[i]) {
			case '+':
				counters.push(op1 + op2);
				*file << to_string(op1) << " + " << to_string(op2) << " = " << to_string(counters.top()) << '\n';
				break;
			case '-':
				counters.push(op1 - op2);
				*file << to_string(op1) << " - " << to_string(op2) << " = " << to_string(counters.top()) << '\n';
				break;
			case '*':
				counters.push(op1 * op2);
				*file << to_string(op1) << " * " << to_string(op2) << " = " << to_string(counters.top()) << '\n';
				break;
			case '/':
				counters.push(op1 / op2);
				*file << to_string(op1) << " / " << to_string(op2) << " = " << to_string(counters.top()) << '\n';
				break;
			}
		}
	}
	*file << '\n';
	return counters.top();
}

int calculateInfix(string in_line) {
	in_line = infixToPostfix(in_line);
	return calculatePostfix(in_line);
}

void generateTest() {
	srand(time(NULL));
	//cout << '\n' << "Место создания файлов(d:\\folder\\folder\\): ";
	string path = "tests";
	//getline(cin, path);
	ofstream ask(path + "ask.txt"), key(path + "key.txt"), ans(path + "ans.txt");
	if (!ask.is_open() || !ans.is_open() || !key.is_open()) {
		std::cout << "Ошибка создания файла" << '\n';
		return;
	}
	int count, temp;
	cout << "Количество вариантов: ";
	cin >> count;
	for (int i = 0; i != count; i++) {
		path = "";
		ask << "Вариант " << i + 1 << '\n';
		ans << "Вариант " << i + 1 << '\n';
		key << "Вариант " << i + 1 << '\n';
		path += to_string(rand() % 9 + 1);
		for (int i = 0; i != 5; i++) {
			path += generateOperator();
			path += to_string(rand() % 9 + 1);
		}
		cout << path << '\n';
		ask << path << '\n';
		ask << "1) Преобразовать выражение в постфиксную и префиксную запись" << '\n';
		ask << "2) Решить это выражение" << '\n';
		key << infixToPostfixFile(path, &ans) << '\n' << '\n';
		key << infixToPrefixFile(path, &ans) << '\n' << '\n';
		key << calculatePostfixFile(infixToPostfix(path), &ans) << '\n' << '\n';
		key << calculatePrefixFile(infixToPrefix(path), &ans) << '\n' << '\n';
	}
	ask.close();
	ans.close();
	key.close();
}

int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	std::string infix, postfix, prefix;
	std::cout << "Введите инфиксное выражение (допускаются числа от 0 до 9 и операторы /*+-, ввод без пробелов):";
	std::getline(std::cin, infix);
	postfix = infixToPostfix(infix);
	prefix = infixToPrefix(infix);
	std::cout << "инфиксное выражение: " << infix << '\n';
	std::cout << "постфиксное выражение: " << postfix << '\n';
	std::cout << "префиксное выражение: " << prefix << '\n' << '\n';
	std::cout << "результат для инфиксного: " << calculateInfix(infix) << '\n';
	std::cout << "результат для постфиксного: " << calculatePostfix(postfix) << '\n';
	std::cout << "результат для префиксного: " << calculatePostfix(postfix) << '\n';
	generateTest();
	return 0;
}