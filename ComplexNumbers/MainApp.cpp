#include <iostream>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>

#include "Complex.h"

using namespace std;

void menu();

void addItem();
void substractItem();
void productItem();
void divideItem();
void trigItem();
void expItem();

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleTitle(TEXT("ComplexApp"));
	system("color 0A");
	system("mode con cols=60 lines=20");
	
	menu();
}

void menu()
{
	system("cls");
	
	cout << "\n\n\t1. Додавання\n" << endl
		<< "\t2. Вiднiмання\n" << endl
		<< "\t3. Множення\n" << endl
		<< "\t4. Дiлення\n" << endl
		<< "\t5. Тригонометрична форма\n" << endl
		<< "\t6. Показникова форма\n" << endl
		<< "\t7. Вихiд\n" << endl;

	char key = '0';

	while(key <= 48 || key > 55)
	{
		key = getch();
	}

	if(key == '7')
	{
		exit(0);
	}

	system("cls");
	
	switch (key)
	{
		case '1':
			addItem();
			break;

		case '2':
			substractItem();
			break;

		case '3':
			productItem();
			break;

		case '4':
			divideItem();
			break;

		case '5':
			trigItem();
			break;

		case '6':
			expItem();
			break;
	}

	cout << "\n\nНатиснiть ESC для повернення до головного меню" << endl;

	do
	{
		key = getch();
	}

	while (key != 27);

	menu();
}

void addItem()
{
	cout << "Перше число\n" << endl;
	
	complex::complexNumber num1 = complex::parseNum();

	cout << "\n\nДруге число\n" << endl;

	complex::complexNumber num2 = complex::parseNum();

	cout << "\n\nРезультат: ";

	complex::print(complex::add(num1, num2));
	
}

void substractItem()
{
	cout << "Перше число\n" << endl;

	complex::complexNumber num1 = complex::parseNum();

	cout << "\n\nДруге число\n" << endl;

	complex::complexNumber num2 = complex::parseNum();

	cout << "\n\nРезультат: ";

	complex::print(complex::subtract(num1, num2));
	
}

void productItem()
{
	cout << "Перше число\n" << endl;

	complex::complexNumber num1 = complex::parseNum();

	cout << "\n\nДруге число\n" << endl;

	complex::complexNumber num2 = complex::parseNum();

	cout << "\n\nРезультат: ";

	complex::print(complex::product(num1, num2));
	
}

void divideItem()
{
	cout << "Перше число\n" << endl;

	complex::complexNumber num1 = complex::parseNum();

	cout << "\n\nДруге число\n" << endl;

	complex::complexNumber num2 = complex::parseNum();

	if(num2.realPart == 0 && num2.imaginaryPart == 0)
	{
		cout << "\n\nДiлення на 0 неможливе" << endl;
		return;
	}
	
	cout << "\n\nРезультат: ";

	complex::print(complex::divide(num1, num2));
	
}

void trigItem()
{
	complex::complexNumber num = complex::parseNum();

	cout << "\n\nРезультат: ";

	complex::trigForm(num);
}

void expItem()
{
	complex::complexNumber num = complex::parseNum();

	cout << "\n\nРезультат: ";
	
	complex::expForm(num);
}



