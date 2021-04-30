#include "Complex.h"
#include <iomanip>
#include <iostream>

namespace complex
{
	complexNumber parseNum() // Зчитування комплексного числа з консолі
	{	
		double numRealP, numImagP;

		cout << "Дiйсна частина: ";

		cin >> numRealP;

		cout << "Уявна частина: ";
		
		cin >> numImagP;
		
		return complexNumber{ numRealP, numImagP };
	}
	
	complexNumber conjugate(complexNumber num) // Пошук спряженого числа
	{
		return complexNumber
		{
			num.realPart,

			-num.imaginaryPart
		};
	}

	complexNumber add(complexNumber num1, complexNumber num2) // Додавання комплексних чисел
	{
		return complexNumber
		{
		   num1.realPart + num2.realPart,

		   num1.imaginaryPart + num2.imaginaryPart
		};
	}

	complexNumber subtract(complexNumber num1, complexNumber num2) // Віднімання комплексних чисел
	{
		return complexNumber
		{
			num1.realPart - num2.realPart,

			num1.imaginaryPart - num2.imaginaryPart
		};
	}

	complexNumber product(complexNumber num1, complexNumber num2) // Множення комплексних чисел
	{
		return complexNumber
		{
		   num1.realPart * num2.realPart - num1.imaginaryPart * num2.imaginaryPart,

		   num1.imaginaryPart * num2.realPart + num1.realPart * num2.imaginaryPart
		};
	}

	complexNumber divide(complexNumber num1, complexNumber num2) // Ділення комплексних чисел
	{	
		int precision = pow(10, 5);

		return complexNumber
		{
			round((product(num1, conjugate(num2)).realPart /
						   product(num2, conjugate(num2)).realPart) * precision) /
						   precision,

			round((product(num1, conjugate(num2)).imaginaryPart /
						   product(num2, conjugate(num2)).realPart) * precision) /
						   precision
		};
	}

	double abs(complexNumber num) // Модуль комплексного числа
	{	
		return sqrt(num.realPart * num.realPart + num.imaginaryPart * num.imaginaryPart);
	}

	void trigForm(complexNumber num) // Тригонометрична форма комплексного числа
	{
		int precision = pow(10, 2);
		
		double r = round( abs(num) * precision ) / precision;
		
		double angle = round(atan2(num.imaginaryPart, num.realPart) * 180 / 3.14159 * precision) / precision;

		cout << r << " * (cos(" << angle << ") + isin(" << angle << "))" << endl;
	}

	void expForm(complexNumber num) // Показникова форма комплексного числа
	{
		int precision = pow(10, 2);

		double r = round(abs(num) * precision) / precision;

		double angle = round(atan2(num.imaginaryPart, num.realPart) * 180 / 3.14159 * precision) / precision;

		cout << r << " * exp("  << angle << "i)" << endl;
	}

	void print(complexNumber num) // Вивід комплексного числа у консоль
	{
		if (num.imaginaryPart == 0)
		{
			cout << num.realPart << endl;
		}
		
		else if(num.realPart == 0)
		{
			cout << num.imaginaryPart << "i" << endl;
		}
		
		else if (num.imaginaryPart > 0)
		{
			cout << num.realPart << " + " << num.imaginaryPart << "i" << endl;
		}

		else if (num.imaginaryPart < 0)
		{
			cout << num.realPart << " - " << num.imaginaryPart * (-1) << "i" << endl;
		}
	}
}
