//This program calculates the gravitational force(Newtons) between two objects
//of mass m1 and m2, and distance d between the two objects
#include <iostream>
#include <string>
#include <cmath>

const double G = 6.67384 * pow(10, -11);
//Gravitational constant

double gravForce(double m1, double m2, double d);

int main()
{
	double mass1, mass2, distance;
	std::string input;
	do{
		std::cout << "Enter mass of first object in kg: ";
		std::cin >> mass1;
		std::cout << "Enter mass of second object in kg: ";
		std::cin >> mass2;
		std::cout << "Enter distance between objects in meters: ";
		std::cin >> distance;

		std::cout << "The force in Newtons between the 2 objects is "
			<< gravForce(mass1, mass2, distance) << std::endl;
		std::cout << "Would you like to calculate another example?(y/n) ";
		std::cin >> input;
		std::cout << std::endl;
	} while (input == "y" || input == "Y");

	return 0;
}

double gravForce(double m1, double m2, double d)
{
	return G * ((m1 * m2) / pow(d, 2));
}