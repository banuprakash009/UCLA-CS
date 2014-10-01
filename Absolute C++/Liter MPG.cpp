//This program takes user input in number of liters consumed by user's car
//and the number of miles travelled by the car and outputs MPG

#include <iostream>
#include <string>

const double LITER = .264179;
//Gallons per Liter

double mpg(double newLiters, double newMiles);
//Returns miles per gallon from liters and miles travelled

int main()
{
	double liters, miles;
	std::string input;
	do{
		std::cout << "How many liters? ";
		std::cin >> liters;
		std::cout << "How many miles? ";
		std::cin >> miles;
		std::cout << std::endl;

		std::cout << "You achieved " << mpg(liters, miles) << " miles per gallon."
			<< "Would you like to continue? (y/n) ";
		std::cin >> input;

	} while (input == "y" || input == "Y");

	return 0;
}

double mpg(double newLiters, double newMiles)
{
	double gallons = newLiters * LITER;
	return (newMiles / gallons);
}