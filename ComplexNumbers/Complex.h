#pragma once
#include <fstream>

using namespace std;

namespace complex
{
	struct complexNumber
	{
		double realPart;
		double imaginaryPart;

	};

	complexNumber parseNum();

	complexNumber conjugate(complexNumber num);

	complexNumber add(complexNumber num1, complexNumber num2);

	complexNumber subtract(complexNumber num1, complexNumber num2);

	complexNumber product(complexNumber num1, complexNumber num2);

	complexNumber divide(complexNumber num1, complexNumber num2);

	double abs(complexNumber num);

	void trigForm(complexNumber num);

	void expForm(complexNumber num);
	
	void print(complexNumber num);


}

