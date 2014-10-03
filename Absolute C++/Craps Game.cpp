//This program simulates playing a game of craps 10,000 times and calculates 
//the percentage of times won at the end. For a summary of rules see: 
//https://en.wikipedia.org/wiki/Craps#Rules_of_play

#include <iostream>
#include <ctime>

int rollDie();
//Simulates roll of 2 die

int main()
{
	srand((int)time(0));
	int firstRoll, point, roll;
	int win = 0;
	int lose = 0;

	for (int i = 0; i < 10000; i++)
	{
		firstRoll = rollDie();
		if (firstRoll == 7 || firstRoll == 11)
		{
			win++;
		}
		else if (firstRoll == 2 || firstRoll == 3 || firstRoll == 12)
		{
			lose++;
		}
		else
		{
			point = firstRoll;
			roll = rollDie();
			while (roll != 7 && roll != point)
			{
				roll = rollDie();
			}
			if (roll == point)
			{
				win++;
			}
			else
			{
				lose++;
			}
		}
	}

	double probability;
	probability = (static_cast<double>(win) / (win + lose));
	std::cout << "Probability of winning is " << probability << ".\n";

	return 0;
}

int rollDie()
{
	int roll1, roll2, totalRoll;
	roll1 = 1 + (rand() % 6);
	roll2 = 1 + (rand() % 6);
	totalRoll = roll1 + roll2;
	return totalRoll;
}