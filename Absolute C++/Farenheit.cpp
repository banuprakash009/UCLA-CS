/* This program calculates the numeric value at which Farenheit = Celsius */

#include <iostream>

int main()
{
	int celsius = 100;
	double faren = 0;

	while (celsius != faren)
	{
		celsius--;
		faren = static_cast<double>(9) / 5 * celsius + 32;
	}
	std::cout << "The numeric value at which Farenheit equals Celsius is " << faren << std::endl;

	return 0;
}