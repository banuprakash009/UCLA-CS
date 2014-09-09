/* This program is designed to check whether a sphere will sink or float in water. Sphere
dimensions are given by user input in lbs. and ft. Bouyant force is calculated according
to F_b = V * GAMMA, where V is the volume and GAMMA the specific weight of the fluid. */

#include <iostream>
#include <cmath>

int main()
{
	const double GAMMA = 62.4, PI = 3.141569;
	double weight, radius;

	std::cout << "Enter weight of sphere in lbs: ";
	std::cin >> weight;
	std::cout << std::endl;
	std::cout << "Enter radius of sphere in feet: ";
	std::cin >> radius;
	std::cout << std::endl;

	double volume = (4 / 3) * PI * pow(radius, 3);
	double buoyForce = volume * GAMMA;

	std::cout << "Buoyant force is " << buoyForce << " lbs.\n";

	if (buoyForce >= weight)
		std::cout << "Object will float.\n";
	else
		std::cout << "Object will sink.\n";

	return 0;
}