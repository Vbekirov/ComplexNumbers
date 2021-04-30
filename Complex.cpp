#include "Complex.h"
#include <iomanip>
#include <iostream>

namespace complex
{
	complexNumber parseNum() // ���������� ������������ ����� � ������
	{	
		double numRealP, numImagP;

		cout << "�i���� �������: ";

		cin >> numRealP;

		cout << "����� �������: ";
		
		cin >> numImagP;
		
		return complexNumber{ numRealP, numImagP };
	}
	
	complexNumber conjugate(complexNumber num) // ����� ���������� �����
	{
		return complexNumber
		{
			num.realPart,

			-num.imaginaryPart
		};
	}

	complexNumber add(complexNumber num1, complexNumber num2) // ��������� ����������� �����
	{
		return complexNumber
		{
		   num1.realPart + num2.realPart,

		   num1.imaginaryPart + num2.imaginaryPart
		};
	}

	complexNumber subtract(complexNumber num1, complexNumber num2) // ³������� ����������� �����
	{
		return complexNumber
		{
			num1.realPart - num2.realPart,

			num1.imaginaryPart - num2.imaginaryPart
		};
	}

	complexNumber product(complexNumber num1, complexNumber num2) // �������� ����������� �����
	{
		return complexNumber
		{
		   num1.realPart * num2.realPart - num1.imaginaryPart * num2.imaginaryPart,

		   num1.imaginaryPart * num2.realPart + num1.realPart * num2.imaginaryPart
		};
	}

	complexNumber divide(complexNumber num1, complexNumber num2) // ĳ����� ����������� �����
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

	double abs(complexNumber num) // ������ ������������ �����
	{	
		return sqrt(num.realPart * num.realPart + num.imaginaryPart * num.imaginaryPart);
	}

	void trigForm(complexNumber num) // ��������������� ����� ������������ �����
	{
		int precision = pow(10, 2);
		
		double r = round( abs(num) * precision ) / precision;
		
		double angle = round(atan2(num.imaginaryPart, num.realPart) * 180 / 3.14159 * precision) / precision;

		cout << r << " * (cos(" << angle << ") + isin(" << angle << "))" << endl;
	}

	void expForm(complexNumber num) // ����������� ����� ������������ �����
	{
		int precision = pow(10, 2);

		double r = round(abs(num) * precision) / precision;

		double angle = round(atan2(num.imaginaryPart, num.realPart) * 180 / 3.14159 * precision) / precision;

		cout << r << " * exp("  << angle << "i)" << endl;
	}

	void print(complexNumber num) // ���� ������������ ����� � �������
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
