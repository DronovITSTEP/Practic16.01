#include <iostream>
#include <algorithm>

using namespace std;

/*
Создайте приложение Калькулятор. Нужно
поддерживать операции +, –, *, /.
Реализовать меню без использования операторов if
и switch при помощи массива указателей на функции.
*/
double add(double a, double b) { return a + b; }
double sub(double a, double b) { return a - b; }
double mult(double a, double b) { return a * b; }
double div(double a, double b) { return (b != 0)? a / b: NULL ; }

void result(double (*p)(double, double), double a, double b) {
	cout << "Результат = " << p(a, b) << endl;
}

/*
Написать программу, которая содержит функцию, 
принимающую в качестве аргумента, указатели
на три массива и размер массивов, Заносит в массив
C суммы элементов массивов А и В. Размер массивов
одинаковый.
*/
void sumC(int* A, int* B, int* C, int s) {
	for (int i = 0; i < s; i++) {
		C[i] = A[i] + B[i];
		cout << C[i] << " ";
	}
}


int main()
{
	setlocale(LC_ALL, "");
	int a, b, c;

	do {
		cout << "Введите число а -> "; cin >> a;
		cout << "Введите число b -> "; cin >> b;

		cout << "Какое действие выполнить?\n"
			<< "1 +\n"
			<< "2 -\n"
			<< "3 *\n"
			<< "4 /\n"
			<< "0 exit\n";

		cin >> c;
		double (*op[])(double, double) { add, sub, mult, div };
		if (c != 0) result(op[c - 1], a, b);
	} while (c != 0);	
}
