/* This program is used to calculate the total grade for N classroom exercises as a percentage.
   The user supplies input value for N followed by scores and totals.*/
#include <iostream>

int main()
{
	int exercises, score, totalScore = 0, possiblePoints, totalPoints = 0;

	std::cout << "How many exercises to input? ";
	std::cin >> exercises;
	std::cout << std::endl;
	for (int i = 1; i <= exercises; i++)
	{
		std::cout << "Score received for exercise " << i << ": ";
		std::cin >> score;
		
		totalScore += score;

		std::cout << "Total points possible for exercise " << i << ": ";
		std::cin >> possiblePoints;
		
		totalPoints += possiblePoints;
		std::cout << std::endl;
	}
	double percent;
	percent = static_cast<double>(totalScore) / totalPoints;
	std::cout << "Your total is " << totalScore << " out of " << totalPoints << ", or "
			  << percent * 100 << "\%." << std::endl;

	return 0;
}
