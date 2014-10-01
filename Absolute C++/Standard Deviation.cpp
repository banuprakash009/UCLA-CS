//This program calculates the standard deviation for a vector of scores

#include <iostream>
#include <string>
#include <cmath>
#include <vector>

double sigma(const std::vector<int> &scores);
//Calculates mean for standard deviation as well as
//standard deviation. Returns standard deviation

int main()
{
	int numScores;
	std::cout << "How many scores to enter? ";
	std::cin >> numScores;
	std::vector<int> scores(numScores);
	int value;

	for (int i = 0; i < numScores; i++)
	{
		std::cout << "Enter score: ";
		std::cin >> value;
		scores[i] = value;
	}
	std::cout << "The standard deviation is " << sigma(scores)
		<< std::endl;
	return 0;
}

double sigma(const std::vector<int> &scores)
{
	double sum = 0;
	double average = 0;
	int length = scores.size();
	for (int i = 0; i < length; i++)
	{
		average += scores[i];
	}

	average = average / scores.size();

	for (int i = 0; i < length; i++)
	{
		sum += pow((scores[i] - average), 2);
	}
	return pow(sum, .5);
}
