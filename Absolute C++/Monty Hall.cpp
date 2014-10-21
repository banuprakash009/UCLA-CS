/*This program is designed to simulate the Monty Hall problem. It runs
10,000 turns of the problem and calculates whether the contestant would
win if they chose to switch doors or stay with original choice. At the end it displays
the percentage of both. For reference see https://en.wikipedia.org/wiki/Monty_Hall_problem */

#include <iostream>
#include <ctime>

void gameshow(int& winStay, int& winSwitch);
//Simulates choosing door for prize and contestant choice. Once chosen,
//determines whether contestant would win by switching doors or staying.

int chooseDoor();
//Choose random door.

int main()
{
	srand((int)time(0));

	int winStay = 0,
		winSwitch = 0;
	for (int i = 0; i < 10000; i++)
	{
		gameshow(winStay, winSwitch);
	}
	std::cout << "Percentage of winning by staying is " << winStay / 10000.0 << ".\n"
		<< "Percentage of winning by switching is " << winSwitch / 10000.0 << ".\n";

	return 0;
}

void gameshow(int& winStay, int& winSwitch)
{
	//Determine which door has prize
	int prize = chooseDoor();

	//Determine which door contestant chooses
	int door = chooseDoor();

	if (prize != door)
		winSwitch++;
	else
		winStay++;
}

int chooseDoor()
{
	return (1 + (rand() % 3));
}