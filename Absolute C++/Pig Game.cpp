/*This is an assignment from the book Absolute C++. This program is designed to
play a game of Pig between a human and computer opponent. Pig is a dice game in
which the first player to roll 100 points wins. On each turn a player rolls a
dice. If they roll a 2-6 they may choose to roll again or hold. If they choose
to hold, the sum of all rolls for the turn are added to thier total score. If
they roll a 1, all points for the turn are forfeit and it becomes the opponent's
turn. The assignment asks for the logic of the turns to be handled inside the
functions.*/

#include <iostream>
#include <ctime>
#include <string>

int humanTurn(int &humTotalScore);
//Roll for human. Roll until hitting a 1 or
//choosing to hold due to prompt.

int computerTurn(int &compTotalScore);
//Takes turn for computer. Keeps rolling until rolling
//either a 1 or accumulating at least 20 points.

int rollDie();
//Simulates rolling of a die.

int main()
{
	srand((int)time(0));

	int humanTotalScore = 0;
	int compTotalScore = 0;

	while (humanTotalScore < 100 && compTotalScore < 100)
	{
		humanTurn(humanTotalScore);
		computerTurn(compTotalScore);

		std::cout << "You have " << humanTotalScore << " and the comp has "
				  << compTotalScore << ".\n";
	}

	if (humanTotalScore >= 100)
		std::cout << "You win!\n";
	else
		std::cout << "The Computer has " << compTotalScore << ". You lose!\n";
	return 0;
}

int humanTurn(int &humTotalScore)
{
	int score = 0;
	bool run = true;
	std::string response;
	int roll = 0;
	do
	{
		roll = rollDie();
		if (roll == 1)
		{
			std::cout << "You rolled a 1. You get no points.\n";
			run = false;
		}
		else
		{
			score += roll;
			std::cout << "You rolled a " << roll
					  << ". Would you like to roll again? (r/h) ";
			std::cin >> response;
			if (response == "h")
			{
				humTotalScore += score;
				run = false;
			}
		}

	} while (run);

	return 0;

}

int computerTurn(int &compTotalScore)
{
	bool run = true;
	int score = 0;
	int roll = 0;
	do
	{
		roll = rollDie();
		if (roll == 1)
		{
			std::cout << "Computer rolls a 1. Your turn.\n";
			score = 0;
			run = false;
		}
		else
		{
			score += roll;
		}

	} while (score < 20 && run);

	compTotalScore += score;
	return 0;
}

int rollDie()
{
	int roll = 1 + (rand() % 6);
	return roll;
}