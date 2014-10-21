/*This program is an exercise from the book Absolute C++. It asks users to
input lengths for the sides of a triangle and then calculates the area and
perimeter based on those lengths.*/

#include <iostream>
#include <cmath>

void triangle(int sideA, int sideB, int sideC, double& area, int& perimeter);
//Calculates the area of a triangle by semiperimeter and also calculates
//perimeter.

int main()
{
	int side1 = 0,
		side2 = 0,
		side3 = 0,
		perimeter = 0;
	double area = 0;

	std::cout << "Enter lengths for triangle to compute area and perimeter. \n";
	std::cout << "Side 1: ";
	std::cin >> side1;
	std::cout << "Side 2: ";
	std::cin >> side2;
	std::cout << "Side 3: ";
	std::cin >> side3;

	triangle(side1, side2, side3, area, perimeter);
	std::cout << "The area is " << area << " and the perimeter is "
		<< perimeter << ".\n";

	return 0;
}

void triangle(int sideA, int sideB, int sideC, double& area, int& perimeter)
{
	//Check for valid triangle inputs
	bool valid1 = (sideA + sideB) > sideC;
	bool valid2 = (sideB + sideC) > sideA;
	bool valid3 = (sideC + sideA) > sideB;

	if (!(valid1 && valid2 && valid3))
	{
		std::cout << "Invalid side lengths.\n";
		exit(0);
	}

	double semi = (sideA + sideB + sideC) / 2.0;
	perimeter = 2 * semi;

	//Area computed as sqrt(s(s-a)(s-b)(s-c)) where s is semiperimeter
	double mult = semi * (semi - sideA) * (semi - sideB) * (semi - sideC);
	area = sqrt(mult);

}